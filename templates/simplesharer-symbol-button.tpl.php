<?php

/**
 * @file
 * Displays symbol button.
 *
 * Available variables:
 * - $iconlibrary: string of which icon library.
 * - $buttonname: HTML class name for the button (e.g. "back30").
 * - $titletext: Text for the HTML title attribute.
 * - $awesomename: Font Awesome Icon name.
 * - $foundationname: Foundation Icon Set name.
 * - $actiontext: Descriptive "action" text for button (e.g. "tweet").
 *
 * @ingroup themeable
 */
?>

<li class="simplesharer-<?php echo $buttonname; ?>-button-item"><a href="<?php echo $url; ?>"><span class="simplesharer-<?php echo $buttonname; ?>-button" title="<?php echo $titletext; ?>" target="_blank">
<?php if ($iconlibrary == 'fontawesome') { ?>
  <i class="fa <?php echo $awesomename; ?>" title="<?php echo $titletext; ?>"></i>
<?php } elseif ($iconlibrary == 'foundation') { ?>
    <i class="fa <?php echo $foundationname; ?>" title="<?php echo $titletext; ?>"></i>
<?php } ?>
<strong class="actiontext"><?php echo $actiontext; ?></strong></span></a></li>
