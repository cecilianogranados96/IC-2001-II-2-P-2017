<?php
	$host    = "localhost";
	$port 	 = 1500;
	$result = "";
	if (isset($_GET['mensaje'])){		
		$message = $_GET['mensaje'];
		$socket = socket_create(AF_INET, SOCK_STREAM, 0);
		$result = socket_connect($socket, $host, $port);  
		if($result){ 
			socket_write($socket, $message, strlen($message));
			$result = socket_read ($socket, 2048);
		}
	}
?>
<form action="s.php" method="GET">
	<input type="text" name="mensaje" autocomplete="off" autofocus>
</form>
<h1>
<?php echo $result; ?>