<?php

namespace App\Core;


abstract class DatabaseDriver
{

	abstract public function setId(Int $id);
	abstract public function getId();

	protected $pdo;
	protected $table;


	public function __construct()
	{
		try{
			$this->pdo = new \PDO("mysql:host=database;dbname=mvcphp;port=3306", "mvcphp_user", "mvcphp_pwd");

			$this->pdo->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
    		$this->pdo->setAttribute(\PDO::ATTR_EMULATE_PREPARES, false);

		}catch(Exception $e){
			die("Erreur SQL ".$e->getMessage());
		}

		$CalledClassExploded = explode("\\", get_called_class());
		$this->table = strtolower(end($CalledClassExploded));
	}

	public function save(): void
	{
		$objectVars = get_object_vars($this);
		$classVars = get_class_vars(get_class());
		$columns = array_diff_key($objectVars, $classVars);

		if(is_null($this->getId())) {
			$sql = "INSERT INTO ".$this->table. " (".implode(",", array_keys($columns) ) .") VALUES (:".implode(",:", array_keys($columns) ) .") ;";
		} else {
			foreach($columns as $column=>$value){
				$sqlUpdate[] = $column."=:".$column;
			}

			$sql = "UPDATE ".$this->table. " SET  ".implode(",",$sqlUpdate)."  WHERE id=".$this->getId();
		}

		$queryPrepared = $this->pdo->prepare($sql);
		$queryPrepared->execute($columns);
	}

	public function count(): array {
		$sql = "SELECT COUNT(id) FROM ".$this->table;
		$queryPrepared = $this->pdo->prepare($sql);
		$queryPrepared->execute();

		$result = $queryPrepared->fetchAll(\PDO::FETCH_ASSOC);
		return $result;
	}

	public function list(int $start, $documentsOnPageNumber): array {
		$sql = "SELECT * FROM ".$this->table." ORDER BY id DESC LIMIT $start, $documentsOnPageNumber";
		$queryPrepared = $this->pdo->prepare($sql);
		$queryPrepared->execute();

		$result = $queryPrepared->fetchAll(\PDO::FETCH_ASSOC);
		return $result;
	}

	public function index(): object {
		$sql = "SELECT * FROM ".$this->table." WHERE id=".$this->getId();
		$queryPrepared = $this->pdo->prepare($sql);
		$queryPrepared->execute();

		$result = $queryPrepared->fetchObject(get_class());
		return $result;
	}
}



