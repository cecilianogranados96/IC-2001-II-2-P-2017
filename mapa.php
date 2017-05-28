	<?php
	if (isset($_GET['cal'])){
		$cargar = "Logica/rutas_cal.php"; 
		$peso = $_GET['peso'];
	}else{
		$cargar = "Logica/rutas.php";
		$peso = "";
	}
	?>
<html>
	<head>
	<title>Aviator - Calcula tus rutas mas facil y rapido</title>
	<link rel="stylesheet" href="css/map.css" type="text/css" media="all" />
	<link href="css/boots.css" rel="stylesheet">
	<link rel="stylesheet" href="https://www.amcharts.com/lib/3/ammap.css" type="text/css" media="all" />
	<script src="js/ammap.js"></script>
	<script src="js/worldLow.js"></script>
	<script src="https://www.amcharts.com/lib/3/plugins/export/examples/export.config.default.js"></script>
	<script src="js/export.min.js"></script>
	<link rel="stylesheet" href="css/export.css" type="text/css" media="all" />
	<script src="js/dark.js"></script>
	<script src="http://code.jquery.com/jquery-1.10.2.min.js"></script>
	<script src="http://code.jquery.com/ui/1.10.3/jquery-ui.min.js"></script>
	<script>
	var targetSVG = "M9,0C4.029,0,0,4.029,0,9s4.029,9,9,9s9-4.029,9-9S13.971,0,9,0z M9,15.93 c-3.83,0-6.93-3.1-6.93-6.93S5.17,2.07,9,2.07s6.93,3.1,6.93,6.93S12.83,15.93,9,15.93 M12.5,9c0,1.933-1.567,3.5-3.5,3.5S5.5,10.933,5.5,9S7.067,5.5,9,5.5 S12.5,7.067,12.5,9z";
	var planeSVG = "m2,106h28l24,30h72l-44,-133h35l80,132h98c21,0 21,34 0,34l-98,0 -80,134h-35l43,-133h-71l-24,30h-28l15,-47";
	var icon = "M21.25,8.375V28h6.5V8.375H21.25zM12.25,28h6.5V4.125h-6.5V28zM3.25,28h6.5V12.625h-6.5V28z";
	AmCharts.exportCFG.menu[0].menu.push(
		{
			"label": "Descargar Kruskal",
			"click": function() {
				alert("Clicked my custom item. Wow cool!");
			}
		}
	);
	var map = AmCharts.makeChart("chartdiv", {
	    "type": "map",
	    "theme": "dark",
	    "dataProvider": {
	        "map": "worldLow",
	        "zoomLevel": 1.5,
	        "zoomLongitude": 5,
	        "zoomLatitude": 40,
	        "lines": [<?php include $cargar; ?>],
	        "images": [<?php include "Logica/aeropuertos.php"; ?>]
	    },
	    "areasSettings": {
	        "unlistedAreasColor": "#8dd9ef"
	    },
	    "imagesSettings": {
	        "color": "#585869",
	        "rollOverColor": "#585869",
	        "selectedColor": "#585869",
	        "pauseDuration": 0.2,
	        "animationDuration": 2.5,
	        "adjustAnimationSpeed": true
	    },
	    "linesSettings": {
	        "color": "#585869",
	        "alpha": 0.4
	    },
	    "export": {
	        "enabled": true,
	        "menu": [{
	            "class": "export-main",
	            "menu": [{
	                "label": "Descargar Warshall",
	                "click": function() {
						$.post('Logica/descargar.php',{opt: 1},function(data) {
								window.open('Logica/Grafo/warshall.txt', '_blank');
						})
	                }
	            },{
	                "label": "Descargar Kruskal",
	                "click": function() {
						$.post('Logica/descargar.php',{opt: 2},function(data) {
								window.open('Logica/Grafo/kruskal.txt', '_blank');
						})
	                }
	            },{
	                "label": "Manual de Usuario",
	                "click": function() {
						window.open('Manual/', '_blank');	
	                }
	            }
				]
	        }]
	    }
	});
	function calcular() {
		$.post('Logica/cal_ruta.php',{
			origen: $("#origen").val(),
			destino:$("#destino").val(),
			algoritmo: $("#algoritmo").val()
			},function(data) {
				window.location.replace("?cal=1&peso="+data);
		})
	}
	function getParameterByName(name) {
		name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
		var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
		results = regex.exec(location.search);
		return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
	}
	function mostrar_costo() {
		if (getParameterByName('cal') == 1){
			$("#busqueda").css("display", "block");
			$(".div1").fadeIn("slow");
			$(".div2").fadeIn("slow");
			if (map.dataProvider.lines.length == 1){
				$(".con_escala").text("----");
				$(".b_con_escala").fadeOut("slow");
				$(".sin_escala").text(" ‎₡ <?php echo $peso;?>");	
			}else{
				$(".con_escala").text(" ‎₡ <?php echo $peso;?>");
				$(".sin_escala").text("----");
				$(".b_sin_escala").fadeOut("slow");
			}
		}
	}	
	</script>
</head>
	<body onload="mostrar_costo();">
		<div id="chartdiv"></div>
		<table class="div1 jumbotron" border="0">
		<tr>
			<td>
				<center>
					<h2>
						Sin escalas:<br>
						<b class="sin_escala" > ‎₡ 5000</b><br>
						<a href="#" onclick="alert('COMPRADO');" class="btn btn-warning b_sin_escala" >Comprar</a>
					</h2>
				</center>
			</td>
		</tr>
		</table>
		<table class="cal jumbotron" border="0">
		<tr>
			<td>
				<select name="origen" class="form-control" id="origen" style="width: 150px;">
				  <option value="1">Origen</option>
				  <?php include "Logica/orig_des.php"; ?>
				</select>
			</td>
			<td>
				 <center><a onclick="calcular();" class="btn btn-success">Calcular</a></center>
			</td>
			<td>
				<select name="destino" class="form-control" id="destino" style="width: 150px;">
				  <option value="1">Destino</option>
				  <?php include "Logica/orig_des.php"; ?>
				</select>
			</td>
		</tr>
		<tr>
			<td>
			</td>
			<td> 
				<select name="algoritmo" class="form-control" id="algoritmo" style="width: 100px;">
				  <option value="1">Dijkstra</option>
				  <option value="2">Floyd</option>
				</select>
			</td>
			<td>
			</td>
		</tr>
		</table>
		<table class="div2 jumbotron" border="0">
		<tr>
			<td>
				<center>
					<h2> 
						Con escalas:<br>
						<b class="con_escala"> ‎₡ 5000</b><br>
						<a href="#" onclick="alert('COMPRADO');" class="btn btn-warning b_con_escala">Comprar</a>
					</h2>
				</center>
			</td>
		</tr>
		</table>
	</body>
</html>