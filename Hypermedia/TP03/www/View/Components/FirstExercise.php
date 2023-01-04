<h1>Liste de documents</h1>

<?php if (empty($data["documents"])): ?>
    <p>Aucun document n'a été enregistré</p>
<?php else: ?>
    <table>
        <thead>
            <tr>
                <th>Id</th>
                <th>Nom</th>
                <th>Extension</th>
                <th>Taille (bytes)</th>
                <th>Chemin</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($data["documents"] as $document): ?>
                <tr>
                    <td><?= $document['id'] ?></td>
                    <td><?= $document['filename'] ?></td>
                    <td><?= $document['extension'] ?></td>
                    <td><?= $document['size'] ?></td>
                    <td><?= $document['path'] ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
    <br>
    <div class="pagination">
        <?php 
            for ($index = 1; $index <= $data["pageNumber"]; $index++) {
                echo "<a href='?page=$index'>$index</a>&nbsp;";
            }
        ?>
    </div>
<?php endif; ?>

<style>
table, th, td {
  border: 1px solid black;
}

h1 {
    margin-bottom: 15px;
}
</style>
