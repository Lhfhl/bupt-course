DROP TABLE IF EXISTS `authorities`;
DROP TABLE IF EXISTS `users`;
DROP TABLE IF EXISTS `books`;
create table users(
                      username varchar_ignorecase(50) not null primary key,
                      password varchar_ignorecase(500) not null,
                      enabled boolean not null
);
create table authorities (
                    `id` bigint(20) NOT NULL AUTO_INCREMENT,
                    username varchar_ignorecase(50) not null,
                    authority varchar_ignorecase(50) not null,
                    PRIMARY KEY (`id`),
                    constraint fk_authorities_users foreign key(username)
                        references users(username)
);
create table books(
                      bookname varchar(50) not null primary key,
                      chapternum varchar(500) not null,
                      author varchar(50) not null
);


