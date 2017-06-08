<?php 
##########################################################################################
# 
# OBJETIVO:
# =========
#
# Forzar descarga del archivo enviado por parametro.
#
#
#
# Desarrollo:
# 
# - Jose Andres Ceciliano Granados
#
#
#########################################################################################
$name = $_GET['file'];
header("Content-disposition: attachment; filename=$name");
header("Content-type: application/octet-stream");
readfile($name);

?>