CREATE TABLE `tlb001reporteincidentevial` (
  `folio` varchar(200) NOT NULL,
  `id_incidentevial` int(11) DEFAULT NULL,
  `id_delegacion_ini` int(11) DEFAULT NULL,
  `fecha` varchar(100) DEFAULT NULL,
  `incidente_c4` varchar(200) DEFAULT NULL,
  `delegacion_ini` varchar(45) DEFAULT NULL,
  `fechacreacion` varchar(45) DEFAULT NULL,
  `mes` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`folio`),
  FOREIGN KEY (id_delegacion_ini) REFERENCES cat001delegaciones(idDelegacion),
  FOREIGN KEY (id_incidentevial) REFERENCES cat002incidentesviales(id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
