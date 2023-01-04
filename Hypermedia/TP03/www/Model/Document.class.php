<?php

namespace App\Model;

use App\Core\DatabaseDriver;

class Document extends DatabaseDriver
{
	private $id = null;
	protected $filename;
	protected $path;
	protected $folder_name;
    protected $extension;
    protected $size;
	private $date_created;
	private $date_updated;


	public function __construct()
	{
		parent::__construct();
	}


    /**
     * @return null
     */
    public function getId(): ?int
    {
        return $this->id;
    }

    /**
     * @param null $id
     */
    //abstract public function setId($id);
    public function setId(Int $id): void
    {
        $this->id = $id;
    }

    /**
     * @return mixed
     */
    public function getFilename(): ?string
    {
        return $this->filename;
    }

    /**
     * @param mixed $filename
     */
    public function setFilename(String $filename): void
    {
        $this->filename = $filename;
    }

    /**
     * @return mixed
     */
    public function getPath(): ?string
    {
        return $this->path;
    }

    /**
     * @param mixed $path
     */
    public function setPath(String $path): void
    {
        $this->path = $path;
    }

    /**
     * @return mixed
     */
    public function getFolderName(): ?string
    {
        return $this->folder_name;
    }

    /**
     * @param mixed $folder_name
     */
    public function setFolderName(String $folder_name): void
    {
        $this->folder_name = $folder_name;
    }

    /**
     * @return mixed
     */
    public function getExtension(): ?string
    {
        return $this->extension;
    }

    /**
     * @param mixed $extension
     */
    public function setExtension(String $extension): void
    {
        $this->extension = $extension;
    }

    /**
     * @return mixed
     */
    public function getSize(): ?string
    {
        return $this->size;
    }

    /**
     * @param mixed $size
     */
    public function setSize(String $size): void
    {
        $this->size = $size;

    }

    /**
     * @return mixed
     */
    public function getDateCreated()
    {
        return $this->date_created;
    }

    /**
     * @return mixed
     */
    public function getDateUpdated()
    {
        return $this->date_updated;
    }

    public function recursiveRead($path) {
        $files = [];
        $dir = opendir($path);
        while ($file = readdir($dir)) {
            if ($file != '.' && $file != '..') {
                if (is_dir($path . '/' . $file)) {
                    $files[$file] = $this->recursiveRead($path . '/' . $file);
                } else { 
                    $files[] = $file;
                } 
            }
        }
        closedir($dir);
        return $files;
    }
}