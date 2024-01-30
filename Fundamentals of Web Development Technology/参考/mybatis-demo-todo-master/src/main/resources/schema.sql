DROP TABLE IF EXISTS `todo`;
CREATE TABLE `todo`
(
    `id`      bigint(20) NOT NULL AUTO_INCREMENT,
    `content` varchar(255) DEFAULT NULL,
    PRIMARY KEY (`id`)
);


