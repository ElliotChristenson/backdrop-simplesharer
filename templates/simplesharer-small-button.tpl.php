<?php

/**
 * @file
 * Displays small symbol button.
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
<?php if ($iconlibrary == 'fontawesome') { ?>
<a href="<?php echo $url; ?>" title="<?php echo $actiontext . ' on ' . $titletext; ?>" target="_blank"><span class="simplesharer-small-<?php echo $buttonname; ?>-button" title="<?php echo $actiontext . ' on ' . $titletext; ?>" target="_blank"><i class="fa <?php echo $awesomename; ?>" title="<?php echo $actiontext . ' on ' . $titletext; ?>"></i></span></a>
<?php } elseif ($iconlibrary == 'foundation') { ?>
<a href="<?php echo $url; ?>" title="<?php echo $actiontext . ' on ' . $titletext; ?>" target="_blank"><span class="simplesharer-small-<?php echo $buttonname; ?>-button" title="<?php echo $actiontext . ' on ' . $titletext; ?>" target="_blank"><i class="<?php echo $foundationname; ?>" title="<?php echo $actiontext . ' on ' . $titletext; ?>"></i></span></a>
<?php } else { ?>
<a href="<?php echo $url; ?>" title="<?php echo $actiontext . ' on ' . $titletext; ?>" target="_blank"><span class="simplesharer-small-<?php echo $buttonname; ?>-button" title="<?php echo $actiontext . ' on ' . $titletext; ?>" target="_blank"><?php echo $titletext; ?>"></span></a>
<?php } ?>
