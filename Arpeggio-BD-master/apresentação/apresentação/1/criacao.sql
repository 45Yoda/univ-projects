-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema Arpeggio
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema Arpeggio
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `Arpeggio` DEFAULT CHARACTER SET utf8 ;
USE `Arpeggio` ;

-- -----------------------------------------------------
-- Table `Arpeggio`.`Pais`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Pais` (
  `IdPais` CHAR(3) NOT NULL,
  `Nome` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`IdPais`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Utilizador`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Utilizador` (
  `IdUtilizador` INT NOT NULL,
  `Username` VARCHAR(45) NOT NULL,
  `DataNascimento` DATE NOT NULL,
  `Telemovel` INT NULL,
  `Email` VARCHAR(45) NOT NULL,
  `Tipo` VARCHAR(45) NOT NULL,
  `Pais` CHAR(3) NOT NULL,
  PRIMARY KEY (`IdUtilizador`),
  INDEX `fk_Utilizador_Pais1_idx` (`Pais` ASC),
  CONSTRAINT `fk_Utilizador_Pais1`
    FOREIGN KEY (`Pais`)
    REFERENCES `Arpeggio`.`Pais` (`IdPais`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Playlist`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Playlist` (
  `IdPlaylist` INT NOT NULL,
  `Nome` VARCHAR(45) NOT NULL,
  `Descricao` VARCHAR(240) NULL,
  `DuracaoTotal` TIME NOT NULL,
  `NrFaixas` INT NOT NULL,
  `Utilizador` INT NOT NULL,
  PRIMARY KEY (`IdPlaylist`),
  INDEX `fk_Playlist_Utilizador1_idx` (`Utilizador` ASC),
  CONSTRAINT `fk_Playlist_Utilizador1`
    FOREIGN KEY (`Utilizador`)
    REFERENCES `Arpeggio`.`Utilizador` (`IdUtilizador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Artista`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Artista` (
  `IdArtista` INT NOT NULL,
  `Nome` VARCHAR(45) NOT NULL,
  `Biografia` VARCHAR(240) NOT NULL,
  `Ranking` INT NOT NULL,
  PRIMARY KEY (`IdArtista`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Album`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Album` (
  `IdAlbum` INT NOT NULL,
  `Nome` VARCHAR(45) NOT NULL,
  `Data` DATE NOT NULL,
  `DuracaoTotal` TIME NOT NULL,
  `Artista` INT NOT NULL,
  PRIMARY KEY (`IdAlbum`),
  INDEX `fk_Album_Artista1_idx` (`Artista` ASC),
  CONSTRAINT `fk_Album_Artista1`
    FOREIGN KEY (`Artista`)
    REFERENCES `Arpeggio`.`Artista` (`IdArtista`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Faixa`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Faixa` (
  `IdFaixa` INT NOT NULL,
  `Nome` VARCHAR(45) NOT NULL,
  `Genero` VARCHAR(45) NOT NULL,
  `Data` DATE NOT NULL,
  `Duracao` TIME NOT NULL,
  `Reproducoes` INT NOT NULL,
  `Album` INT NULL,
  `Artista` INT NOT NULL,
  PRIMARY KEY (`IdFaixa`),
  INDEX `fk_Faixa_Album1_idx` (`Album` ASC),
  INDEX `fk_Faixa_Artista1_idx` (`Artista` ASC),
  CONSTRAINT `fk_Faixa_Album1`
    FOREIGN KEY (`Album`)
    REFERENCES `Arpeggio`.`Album` (`IdAlbum`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Faixa_Artista1`
    FOREIGN KEY (`Artista`)
    REFERENCES `Arpeggio`.`Artista` (`IdArtista`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Utilizador_follows_Artista`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Utilizador_follows_Artista` (
  `IdUtilizador` INT NOT NULL,
  `IdArtista` INT NOT NULL,
  PRIMARY KEY (`IdUtilizador`, `IdArtista`),
  INDEX `fk_Utilizador_has_Artista_Artista1_idx` (`IdArtista` ASC),
  INDEX `fk_Utilizador_has_Artista_Utilizador_idx` (`IdUtilizador` ASC),
  CONSTRAINT `fk_Utilizador_has_Artista_Utilizador`
    FOREIGN KEY (`IdUtilizador`)
    REFERENCES `Arpeggio`.`Utilizador` (`IdUtilizador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Utilizador_has_Artista_Artista1`
    FOREIGN KEY (`IdArtista`)
    REFERENCES `Arpeggio`.`Artista` (`IdArtista`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Utilizador_follows_Playlist`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Utilizador_follows_Playlist` (
  `IdUtilizador` INT NOT NULL,
  `IdPlaylist` INT NOT NULL,
  PRIMARY KEY (`IdUtilizador`, `IdPlaylist`),
  INDEX `fk_Utilizador_has_Playlist_Playlist1_idx` (`IdPlaylist` ASC),
  INDEX `fk_Utilizador_has_Playlist_Utilizador1_idx` (`IdUtilizador` ASC),
  CONSTRAINT `fk_Utilizador_has_Playlist_Utilizador1`
    FOREIGN KEY (`IdUtilizador`)
    REFERENCES `Arpeggio`.`Utilizador` (`IdUtilizador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Utilizador_has_Playlist_Playlist1`
    FOREIGN KEY (`IdPlaylist`)
    REFERENCES `Arpeggio`.`Playlist` (`IdPlaylist`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Arpeggio`.`Playlist_has_Faixa`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Arpeggio`.`Playlist_has_Faixa` (
  `IdPlaylist` INT NOT NULL,
  `IdFaixa` INT NOT NULL,
  PRIMARY KEY (`IdPlaylist`, `IdFaixa`),
  INDEX `fk_Playlist_has_Faixa_Faixa1_idx` (`IdFaixa` ASC),
  INDEX `fk_Playlist_has_Faixa_Playlist1_idx` (`IdPlaylist` ASC),
  CONSTRAINT `fk_Playlist_has_Faixa_Playlist1`
    FOREIGN KEY (`IdPlaylist`)
    REFERENCES `Arpeggio`.`Playlist` (`IdPlaylist`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Playlist_has_Faixa_Faixa1`
    FOREIGN KEY (`IdFaixa`)
    REFERENCES `Arpeggio`.`Faixa` (`IdFaixa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
