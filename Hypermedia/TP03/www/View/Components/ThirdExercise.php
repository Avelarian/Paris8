<div id="jstree">
    <?php if (empty($data["files"])): ?>
        <p>Aucun dossier n'a été enregistré</p>
    <?php else: ?>
        <ul>
            <?php foreach ($data["files"] as $key => $folder): ?>
                <?php if (is_array($folder)): ?>
                    <li>
                    <?= $key ?>
                        <ul>
                        <?php foreach ($folder as $child): ?>
                            <li>
                              <?= $child ?>
                              <?php if (is_array($child)): ?>
                                  <ul>
                                      <?php foreach ($child as $grandChild): ?>
                                          <li>
                                              <?= $grandChild ?>
                                          </li>
                                      <?php endforeach; ?>
                                  </ul>
                              <?php endif; ?>
                            </li>
                        <?php endforeach; ?>
                        </ul>
                    </li>
                    <?php else: ?>
                        <li data-jstree="<?= $key ?>">
                    <?= $folder ?>
                    </li>
                <?php endif; ?>
            <?php endforeach; ?>
        </ul>
    <?php endif; ?>
</div>

<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/1.12.1/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jstree/3.2.1/jstree.min.js"></script>
<script>
    $(function () { 
        $('#jstree').jstree()
    });
</script>