<?php
$file = fopen("Logica/Grafo/aeropuertos.txt","r");
$data ="";
$x = 0;
$healthy = array("Aeropuerto", "Internacional", "de");
while(!feof($file))
{
	$p = explode(",", fgets($file));
	$p = str_replace($healthy, " ", $p[0]);
	$data .= '<option value="'.$x.'">'.$p.'</option>';
	$x++;
}
echo $data;
fclose($file);
?>