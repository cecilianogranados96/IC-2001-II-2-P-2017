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
$data .= '{
  "svgPath": planeSVG,
  "positionOnLine": 0,
  "color": "#000000",
  "animateAlongLine": true,
  "lineId": "line1",
  "flipDirection": false,
  "loop": true,
  "scale": 0.05,
  "positionScale": 2
}';
echo $data;
fclose($file);
?>