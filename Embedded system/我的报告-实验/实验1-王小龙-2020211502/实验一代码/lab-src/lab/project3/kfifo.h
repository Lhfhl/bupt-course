
#ifndef PROJECT3_KFIFO_H_
#define PROJECT3_KFIFO_H_

/*
 * A simple kernel FIFO implementation.
 *
 * Copyright (C) 2004 Stelian Pop <stelian@popies.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */
#include "kern/task_api.h"
#include "kern/kern_port.h"

#define FIFO_HEADER			\
	unsigned int size;	/* the size of the allocated buffer, must be a power of 2*/			\
	unsigned int in;	/* data is added at offset (in % size) */					\
	unsigned int out;	/* data is extracted from off. (out % size) */				

struct kfifo {
	FIFO_HEADER
	unsigned char buffer[1];	/* the buffer holding the data */
};

#define DEFINE_KFIFO(fifo_name, size_order)				\
struct kfifo_##fifo_name {								\
	FIFO_HEADER											\
	unsigned char buffer[1 << (size_order)];			\
} __##fifo_name = {										\
	1 << (size_order), 0, 0, {0}						\
};														\
struct kfifo *fifo_name = (struct kfifo *)&__##fifo_name;

extern unsigned int __kfifo_put(struct kfifo *fifo, unsigned char *buffer, unsigned int len);
extern unsigned int __kfifo_get(struct kfifo *fifo, unsigned char *buffer, unsigned int len);

/*
 * __kfifo_reset - removes the entire FIFO contents, no locking version
 * @fifo: the fifo to be emptied.
 */
static inline void __kfifo_reset(struct kfifo *fifo)
{
	fifo->in = fifo->out = 0;
}

/*
 * kfifo_reset - removes the entire FIFO contents
 * @fifo: the fifo to be emptied.
 */
static inline void kfifo_reset(struct kfifo *fifo)
{
	WITHIN_CRITICAL() {
		__kfifo_reset(fifo);
	}
}

/*
 * kfifo_put - puts some data into the FIFO
 * @fifo: the fifo to be used.
 * @buffer: the data to be added.
 * @len: the length of the data to be added.
 *
 * This function copies at most 'len' bytes from the 'buffer' into
 * the FIFO depending on the free space, and returns the number of
 * bytes copied.
 */
static inline unsigned int kfifo_put(struct kfifo *fifo,
				     unsigned char *buffer, unsigned int len)
{
	unsigned int ret;

	WITHIN_CRITICAL() {
		ret = __kfifo_put(fifo, buffer, len);
	}

	return ret;
}

/*
 * kfifo_get - gets some data from the FIFO
 * @fifo: the fifo to be used.
 * @buffer: where the data must be copied.
 * @len: the size of the destination buffer.
 *
 * This function copies at most 'len' bytes from the FIFO into the
 * 'buffer' and returns the number of copied bytes.
 */
static inline unsigned int kfifo_get(struct kfifo *fifo,
				     unsigned char *buffer, unsigned int len)
{
	unsigned int ret;

	WITHIN_CRITICAL() {
		ret = __kfifo_get(fifo, buffer, len);

		/*
		* optimization: if the FIFO is empty, set the indices to 0
		* so we don't wrap the next time
		*/
		if (fifo->in == fifo->out)
			fifo->in = fifo->out = 0;
	}

	return ret;
}

/*
 * __kfifo_len - returns the number of bytes available in the FIFO, no locking version
 * @fifo: the fifo to be used.
 */
static inline unsigned int __kfifo_len(struct kfifo *fifo)
{
	return fifo->in - fifo->out;
}

/*
 * kfifo_len - returns the number of bytes available in the FIFO
 * @fifo: the fifo to be used.
 */
static inline unsigned int kfifo_len(struct kfifo *fifo)
{
	unsigned int ret;

	WITHIN_CRITICAL() {
		ret = __kfifo_len(fifo);
	}

	return ret;
}

static inline int __kfifo_is_empty(struct kfifo *fifo) {
	return (fifo->in == fifo->out);
}

static inline int kfifo_is_empty(struct kfifo *fifo) {
	int ret;
	WITHIN_CRITICAL() {
		ret = __kfifo_is_empty(fifo);
	}
	return ret;
}

static inline int __kfifo_is_full(struct kfifo *fifo) {
	return (__kfifo_len(fifo) >= fifo->size);
}

static inline int kfifo_is_full(struct kfifo *fifo) {
	int ret;
	WITHIN_CRITICAL() {
		ret = __kfifo_is_full(fifo);
	}
	return ret;
}

#endif /* PROJECT3_KFIFO_H_ */
