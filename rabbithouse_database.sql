-- phpMyAdmin SQL Dump
-- version 4.6.4
-- https://www.phpmyadmin.net/
--
-- Host: fdb34.awardspace.net
-- Generation Time: 2021 年 8 月 02 日 07:26
-- サーバのバージョン： 5.7.20-log
-- PHP Version: 5.5.38

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `3891466_rabbithouse`
--

-- --------------------------------------------------------

--
-- テーブルの構造 `SensorData`
--

CREATE TABLE `SensorData` (
  `id` int(6) UNSIGNED NOT NULL,
  `sensor` varchar(30) NOT NULL,
  `location` varchar(30) NOT NULL,
  `value1` float DEFAULT NULL,
  `value2` float DEFAULT NULL,
  `time_act` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `mua` text,
  `dudoanmua` text
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- テーブルのデータのダンプ `SensorData`
--

INSERT INTO `SensorData` (`id`, `sensor`, `location`, `value1`, `value2`, `time_act`, `mua`, `dudoanmua`) VALUES
(1621, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:10:27', 'Khong co mua', 'KhÃ´ng mÆ°a'),
(1622, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:10:35', 'Khong co mua', 'KhÃ´ng mÆ°a'),
(1623, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:10:43', 'Khong co mua', 'KhÃ´ng mÆ°a'),
(1624, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:10:50', 'Khong co mua', 'KhÃ´ng mÆ°a'),
(1625, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:10:58', 'Khong co mua', 'KhÃ´ng mÆ°a'),
(1626, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:13:54', 'Khong co mua', 'KhÃ´ng mÆ°a'),
(1627, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:14:01', 'Khong co mua', 'KhÃ´ng mÆ°a'),
(1628, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:14:14', 'Co mua', 'KhÃ´ng mÆ°a'),
(1629, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:14:27', 'Co mua', 'KhÃ´ng mÆ°a'),
(1630, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:14:39', 'Co mua', 'KhÃ´ng mÆ°a'),
(1631, 'DHT11', 'RabbitHouse', 33.6, 60, '2021-08-02 13:14:52', 'Co mua', 'KhÃ´ng mÆ°a'),
(1632, 'DHT11', 'RabbitHouse', 33.7, 60, '2021-08-02 13:16:04', 'Khong co mua', 'KhÃ´ng mÆ°a');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `SensorData`
--
ALTER TABLE `SensorData`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `SensorData`
--
ALTER TABLE `SensorData`
  MODIFY `id` int(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1633;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
