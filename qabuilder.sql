/*
 Navicat Premium Data Transfer

 Source Server         : qabuilder
 Source Server Type    : MariaDB
 Source Server Version : 100510
 Source Host           : 127.0.0.1:3306
 Source Schema         : qabuilder

 Target Server Type    : MariaDB
 Target Server Version : 100510
 File Encoding         : 65001

 Date: 27/05/2021 00:16:20
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for books
-- ----------------------------
DROP TABLE IF EXISTS `books`;
CREATE TABLE `books` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '书索引',
  `name` varchar(255) DEFAULT '' COMMENT '书名',
  `description` text DEFAULT '' COMMENT '书描述',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of books
-- ----------------------------
BEGIN;
INSERT INTO `books` VALUES (1, '数学分析', '微积分学');
COMMIT;

-- ----------------------------
-- Table structure for chapters
-- ----------------------------
DROP TABLE IF EXISTS `chapters`;
CREATE TABLE `chapters` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT '章节名',
  `description` text COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT '注释',
  `bookid` int(11) NOT NULL COMMENT '对应书目id',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of chapters
-- ----------------------------
BEGIN;
INSERT INTO `chapters` VALUES (1, '数学分析基础', '基本功', 1);
COMMIT;

-- ----------------------------
-- Table structure for qa
-- ----------------------------
DROP TABLE IF EXISTS `qa`;
CREATE TABLE `qa` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '题号',
  `content` text DEFAULT NULL COMMENT '题目内容',
  `answer` text DEFAULT NULL COMMENT '答案',
  `comment` text DEFAULT NULL COMMENT '注释',
  `book` int(255) DEFAULT 0 COMMENT '书目[初始为0]',
  `chapter` int(255) DEFAULT 0 COMMENT '章节[初始为0]',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of qa
-- ----------------------------
BEGIN;
INSERT INTO `qa` VALUES (1, '试证明: $1>0$', NULL, NULL, 1, 1);
COMMIT;

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(255) DEFAULT NULL,
  `password` varchar(64) DEFAULT NULL,
  `priv` tinyint(255) DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of users
-- ----------------------------
BEGIN;
INSERT INTO `users` VALUES (1, 'qabuilder', '159a4536b9c7137bdda3116800b7763a4d8fd045f6fe5ce7c8c868b63e26004f', 1);
COMMIT;

SET FOREIGN_KEY_CHECKS = 1;
