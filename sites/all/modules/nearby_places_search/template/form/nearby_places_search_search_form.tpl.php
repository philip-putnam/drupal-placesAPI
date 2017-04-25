<?php
/**
 * @file
 * Near By Place Search form tpl file.
 */
?>

<div id="container">
  <div id="map-content">
    <div id="address_cls">
      <?php print render($form['address']); ?>
    </div>
    <?php print render($form['custom-btn']); ?>
    <div id="map-container"></div> 
    <div id="bottom-section">
      <?php print render($form['latitude']); ?>
      <?php print render($form['longitude']); ?>
    </div>
  </div>
  <div id="navbar">
    <?php print render($form['types']); ?>
  </div>
</div>
