<?php

/**
 * @file
 * Displays CSS for Simplesharer Color.
 *
 * Available variables:
 * - $simplesharer_basecolor:        CSS hex color code for "base" color.
 * - $simplesharer_linkcolor:        CSS hex color code for "link" color.
 * - $simplesharer_topcolor:         CSS hex color code for "top" color.
 * - $simplesharer_bottomcolor:      CSS hex color code for "bottom" color.
 * - $simplesharer_shadowcolor:      CSS hex color code for "shadow" color.
 *
 * @ingroup themeable
 */
?>
<style>
  #simplesharer .simplesharer-button-itemlist li a {
    background: <?php echo $simplesharer_basecolor.";"; ?>
    background: -webkit-linear-gradient(<?php echo $simplesharer_topcolor.",".$simplesharer_basecolor." 40%,".$simplesharer_bottomcolor.");"; ?>
    background: -o-linear-gradient(<?php echo $simplesharer_topcolor.",".$simplesharer_basecolor." 40%,".$simplesharer_bottomcolor.");"; ?>
    background: -moz-linear-gradient(<?php echo $simplesharer_topcolor.",".$simplesharer_basecolor." 40%,".$simplesharer_bottomcolor.");"; ?>
    background: linear-gradient(<?php echo $simplesharer_topcolor.",".$simplesharer_basecolor." 40%,".$simplesharer_bottomcolor.");"; ?>
    box-shadow: 0 1px 0 <?php echo $simplesharer_shadowcolor; ?> initial;
    color: <?php echo $simplesharer_linkcolor.";"; ?>
    text-decoration: none;
    display: block;
  }
  #simplesharer .simplesharer-buttonlist li a:hover {
    text-decoration: none;
  }
  </style>
