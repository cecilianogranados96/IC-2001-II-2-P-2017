<?php
##########################################################################################
# 
# OBJETIVO:
# =========
#
# Iniciar socket.
#
# Parametros:
# ===========
#
#
# Desarrollo:
# 
# - Jose Andres Ceciliano Granados
#
#
#########################################################################################
if (isset($_GET['opt'])){
	system('Grafo\bin\Debug\Grafo.exe');
	//echo "start";
}else{
	$output = shell_exec('taskkill /F /IM "Grafo.exe"');
	//echo "down";
	echo "<script>window.location='../index.php'</script>";
}
?>