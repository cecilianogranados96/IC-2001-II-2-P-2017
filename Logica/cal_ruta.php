<?php
##########################################################################################
# 
# OBJETIVO:
# =========
#
# Comunicarse con el socket y enviar parametros.
#
#
#
# Desarrollo:
# 
# - Jose Andres Ceciliano Granados
#
#
#########################################################################################
	$host    = "localhost";
	$port    = 1500;
	if (isset($_POST['origen'])){		
		$origen = $_POST['origen'];
		$destino = $_POST['destino'];
		$algoritmo = $_POST['algoritmo'];
	}else{
		$origen = $_GET['origen'];
		$destino = $_GET['destino'];
		$algoritmo = $_GET['algoritmo'];
	}

	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("<script>window.location='index.php'</script>");
	socket_write($socket, 0, strlen(0))or die("<script>window.location='index.php'</script>");
	$result = socket_read ($socket, 2048) or die("<script>window.location='index.php'</script>");

	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("ERROR");
	socket_write($socket, $algoritmo, strlen($algoritmo)) or die("ERROR");
	$result = socket_read ($socket, 2048) or die("ERROR");
	
	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("ERROR");
	socket_write($socket, $origen, strlen($origen)) or die("ERROR");	
	$result = socket_read ($socket, 2048) or die("ERROR");

	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("ERROR");
	socket_write($socket, $destino, strlen($destino)) or die("ERROR");	
	$result = socket_read ($socket, 2048) or die("ERROR");
	
	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("ERROR");
	socket_write($socket, 0, strlen(0)) or die("ERROR");	
	$result = socket_read ($socket, 2048) or die("ERROR");

	echo $result;
?>