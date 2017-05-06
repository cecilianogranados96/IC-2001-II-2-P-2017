<?php
$file = fopen("Datos/aeropuertos.txt","r");
$data = "";
$x = 1;
while(!feof($file))
{
$p = explode(",", fgets($file));
$w = trim($p[3]);
$s = "<img style='width:200px;' src='".$w."'>";
$data .= '{
      "svgPath": targetSVG,
	  "id": '.$x.',
      "title": "'.$p[0].'",
      "latitude":  '.$p[1].',
      "longitude": '.$p[2].',
	  "description": "'.$s.'",
	  "zoomLevel": 5,
	  "labelShiftY": 2,
	  "scale": 1
    },';
$x++;
}

$data = substr($data, 0, -1);
echo $data;
fclose($file);

?>