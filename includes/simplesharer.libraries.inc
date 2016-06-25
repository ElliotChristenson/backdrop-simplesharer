<?php

/**
 * Implements hook_libraries_info().
 *
 * For defining external libraries.
 */
function simplesharer_libraries_info() {

  $libraries['fontawesome'] = array(
    'name' => 'Font Awesome',
    'vendor url' => 'http://fortawesome.github.io/Font-Awesome/',
    'download url' => 'http://fortawesome.github.io/Font-Awesome/#modal-download',
    'version arguments' => array(
      'file' => 'css/font-awesome.min.css',
      'pattern' => '/Font Awesome (\d+)\.(\d+)\.(\d+)/',
      'lines' => 3,
    ),
    'files' => array(
      'css' => array('css/font-awesome.min.css'),
    ),
  );
  $libraries['foundation'] = array(
    'name' => 'Foundation Icon Set',
    'vendor url' => 'http://zurb.com/playground/foundation-icon-fonts-3',
    'download url' => 'http://zurb.com/playground/uploads/upload/upload/288/foundation-icons.zip',
    'version arguments' => array(
      'file' => 'foundation-icons/foundation-icons.css',
      'pattern' => '/Foundation Icons v (\d+)\.(\d+)/',
      'lines' => 3,
    ),
    'files' => array(
      'css' => array('foundation-icons/foundation-icons.css'),
    ),
  );

  return $libraries;
}

/**
 * Custom function to detect and load an icon library.
 *
 * @param string $library_name
 *   Name of the icon library e.g. fontawesome, foundation.
 *
 * @return bool
 *
 *   returns whether icon library exists.
 */
function simplesharer_library($library_name) {
  if (($library=libraries_load($library_name)) && !empty($library['loaded'])) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Custom function to check preference and .
 *
 * @param string $block_name
 *   Name of the Drupal block.
 *
 * @return string
 *
 *   returns the name of the library for the chosen block.
 */
function simplesharer_iconlibrary($block_name) {
  $iconlibrary = variable_get($block_name . '_library');
  if (simplesharer_library($iconlibrary)) {
    return $iconlibrary;
  }
  return '';
}
