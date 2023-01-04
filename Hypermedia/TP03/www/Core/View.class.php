<?php

namespace App\Core;


class View{

	private $view;
	private $data = [];

	public function __construct()
	{
		$this->setView("Front");
	}

	public function setView(String $view): void
	{
		$view = "View/".$view.".view.php";
		if(!file_exists($view)){
			die("La vue ".$view." n'existe pas");
		}
		$this->view = $view;
	}

	public function assign(String $key, $value): void
	{
		$this->data[$key] = $value;
	}

	public function includeComponent(String $component = "form", Array $data = []): void
	{
		$component = "View/Components/".$component.".php";
		if(!file_exists($component)){
			die("Le composant ".$component." n'existe pas");
		}
		include $component;
	}

	public function __destruct()
	{
		extract($this->data);
		require $this->view;
	}
}

