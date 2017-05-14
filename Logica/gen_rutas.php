<?php

for ($x=0;$x<59;$x++){
	$s = rand(0,59);
	for ($i=0;$i<$s;$i++){
		if($x != $i){
			$rutas[] = $x.",".$i;
			//echo $x.",".$i."<BR>";
		}
	}
}

print_r($rutas);
?>