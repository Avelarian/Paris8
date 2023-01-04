<?php

namespace App;

define ('ROOT_PATH', realpath(dirname(__FILE__)));

spl_autoload_register(function ( $class ){
	$filename = str_replace("App\\", "", $class);
	$filename = str_replace("\\", "/", $filename);
	$filename =  $filename.".class.php";

	if(file_exists($filename)){
		include $filename;
	}
});

$request = $_SERVER['REQUEST_URI'];
$requestExploded = explode("?", $request);
$uri = strtolower($requestExploded[0]);

$routing = new Core\Routing();
$routing->setAction($uri);
$routing->run();
