<?php
$myFile = "Datos/aeropuertos.txt";
$lines = file($myFile);
$file = fopen("Datos/rutas.txt","r");
$data ="";
$x = 0;
while(!feof($file))
{
$x++;
$p = explode(",", fgets($file));
$r1 = explode(",", $lines[$p[0]+1]);
$r2 = explode(",", $lines[$p[1]+1]);
$data .= '
	{
      "id": "line1",
      "arc": -0.85,
      "alpha": 2.0,
	  "svgPath": icon,
      "latitudes": [ '.$r1[1].','.$r2[1].'],
      "longitudes": ['.$r1[2].','.$r2[2].']
	},';
}
$data = substr($data, 0, -1);
echo $data;
fclose($file);
?>