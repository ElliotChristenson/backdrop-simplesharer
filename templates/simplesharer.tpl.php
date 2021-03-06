<?php

/**
 * @file
 * Displays Social SimpleSharer.
 *
 * Available variables:
 * - $simplesharer_color_css: CSS generated by block config.
 * - $simplesharer_facebook_button: HTML for "facebook" button.
 * - $simplesharer_twitter_button: HTML for "twitter" button.
 * - $simplesharer_pinterest_button: HTML for "pinterest" button.
 * - $simplesharer_linkedin_button: HTML for "linkedin" button.
 * - $simplesharer_tumblr_button: HTML for "tumblr" button.
 * - $simplesharer_reddit_button: HTML for "reddit" button.
 * - $simplesharer_email_button: HTML for "email" button.
 *
 * @ingroup themeable
 */
?>
<div id ="simplesharer" class="simplesharer">
  <?php echo $simplesharer_color_css; ?>
  <ul class="simplesharer-button-itemlist">
    <?php echo $simplesharer_facebook_button; ?>
    <?php echo $simplesharer_twitter_button; ?>
    <?php echo $simplesharer_pinterest_button; ?>
    <?php echo $simplesharer_linkedin_button; ?>
    <?php echo $simplesharer_tumblr_button; ?>
    <?php echo $simplesharer_reddit_button; ?>
    <?php echo $simplesharer_email_button; ?>
  </ul>
</div>
