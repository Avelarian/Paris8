<?php

namespace App\Controller;

use App\Core\View;
use App\Model\Document as DocumentModel;

class Document {

	public function main(): void
	{
        $document = new DocumentModel();

        // List
        $documentsOnPageNumber = 5;
		$pageNumber = ceil($document->count()[0]['COUNT(id)']/$documentsOnPageNumber);
        $page = $_GET['page'] ?? 1;
        $start = ($page - 1) * $documentsOnPageNumber;

        $documents = $document->list($start, $documentsOnPageNumber);

        // Create
        if (!empty($_FILES))
		{
            [$filename, $extension] = explode('.', $_FILES['file']['name']);
            $size = $_FILES['file']['size'];
            $path = "/Uploads/";

            $document->setFilename($filename);
            $document->setFolderName('Uploads');
            $document->setExtension($extension);
            $document->setSize($size);
            $document->setPath($path);

            if(move_uploaded_file($_FILES['file']['tmp_name'], ROOT_PATH.$path.$filename.".".$extension)) {
                echo "The file ".$filename." has been uploaded";
                $document->save();
                $documents = $document->list($start, $documentsOnPageNumber);
            } else {
                echo "There was an error uploading the file, please try again!";
            }
		}

        // Recursive reading
        $systemPath = ROOT_PATH."/Uploads/";
        $files = $document->recursiveRead($systemPath);

        // View config
        $view = new View();
		$view->assign("documents", $documents ?? []);
		$view->assign("pageNumber", $pageNumber ?? 0);
		$view->assign("page", $page ?? 0);
		$view->assign("files", $files ?? []);
	}
}




