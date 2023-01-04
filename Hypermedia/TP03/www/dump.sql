SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";

CREATE TABLE `document` (
  `id` int(11) NOT NULL,
  `filename` varchar(255) NOT NULL,
  `path` varchar(255) NOT NULL,
  `folder_name` varchar(255) NOT NULL,
  `extension` varchar(255) NOT NULL,
  `size` varchar(255) NOT NULL DEFAULT '0',
  `date_created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `date_updated` timestamp NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

ALTER TABLE `document`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `document`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;
