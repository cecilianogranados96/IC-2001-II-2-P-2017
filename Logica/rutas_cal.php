<?php
$myFile = "Datos/aeropuertos.txt";
$lines = file($myFile);
$file = fopen("Datos/rutas_cal.txt","r");
$lat = "";
$lon = "";
while(!feof($file))
{
	$dato = fgets($file);
	$r1 = explode(",", $lines[intval($dato)]);
	$lat .= $r1[1].',';
	$lon .= $r1[2].',';
}
$lat = substr($lat, 0, -1);
$lon = substr($lon, 0, -1);
echo '
	{
      "id": "line1",
      "arc": -0.85,
      "alpha": 2.0,
	  "svgPath": icon,
      "latitudes": [ '.$lat.'],
      "longitudes": ['.$lon.']
	}';
fclose($file);
?>