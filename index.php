<html>
	<head>
		<meta charset="UTF-8" />
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<title>The Aviator</title>
		<link href='https://fonts.googleapis.com/css?family=Playfair+Display:400,700,700italic' rel='stylesheet' type='text/css'>
		<link rel="stylesheet" type="text/css" href="css/demo.css" />
		<link rel="stylesheet" type="text/css" href="css/game.css" />
		<script type="text/javascript" src="js/TweenMax.min.js"></script>
		<script type="text/javascript" src="js/three.min.js"></script>
		<script type="text/javascript" src="js/game.js" /></script>
		<!--[if IE]>
		  <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->
	</head>
	<body>
		<div class="game-holder" id="gameHolder">
			<div class="header">
				<h1>Aviador</h1>
				<h2>Calcula tus rutas mas cercanas</h2>
				<div class="score" id="score">
					<div class="score__content" id="level">
						<div class="score__label">Nivel</div>
						<div class="score__value score__value--level" id="levelValue">1</div>
						<svg class="level-circle" id="levelCircle" viewbox="0 0 200 200">
							<circle id="levelCircleBgr" r="80" cx="100" cy="100" fill="none" stroke="#d1b790" stroke-width="24px" />
							<circle id="levelCircleStroke" r="80" cx="100" cy="100" fill="none" #f25346 stroke="#68c3c0" stroke-width="14px" stroke-dasharray="502" />
						</svg>
					</div>
					<div class="score__content" id="dist">
						<div class="score__label">Distancia</div>
						<div class="score__value score__value--dist" id="distValue">000</div>
					</div>
					<div class="score__content" id="energy">
						<div class="score__label">Energia</div>
						<div class="score__value score__value--energy" id="energyValue">
							<div class="energy-bar" id="energyBar"></div>
						</div>
					</div>
				</div>
			</div>
			<div class="world" id="world"></div>
			<div class="message message--replay" id="replayMessage">Click para reiniciar</div>
			<div class="message message--instructions" id="instructions">Las mejores rutas en un <span>lugar aviador</span></div>
		</div>
		<nav class="meta">
			<a class="demo-link" href="Manual" target="_Blanck">Ayuda</a>
		</nav>
		<div class="partisan">
			<svg class="partisan__bg" viewBox="0 0 500 188" preserveAspectRatio="none" width="100%" height="100%" aria-hidden="true">
				<polygon points="0 154 123.39 0 235.78 14.79 365.6 28.9 436.24 114.93 500 188 0 188 0 154" fill="#bed730"/>
				<polygon points="0 188 108.84 18.17 347.91 26.79 500 188 365.6 28.9 123.39 0 0 154 0 188" fill="#dde465"/>
			</svg>
			<a class="partisan__link" href="mapa.php" rel="nofollow">
				<img class="partisan__img" src="img/b.png">
			</a>
		</div>
	</body>
</html>