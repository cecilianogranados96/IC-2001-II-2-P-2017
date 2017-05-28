<?php
	$host    = "localhost";
	$port    = 1500;
	if (isset($_POST['opt'])){		
		$opt = $_POST['opt'];
	}else{
		$opt = $_GET['opt'];
	}

	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("ERROR");
	socket_write($socket, $opt, strlen($opt)) or die("ERROR");
	$result = socket_read ($socket, 2048) or die("ERROR");
	
	echo $result;
?>