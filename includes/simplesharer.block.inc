<?php

/**
 * Implements hook_block_info().
 */
function simplesharer_block_info() {
  $blocks = array();
  $blocks['simplesharer'] = array(
    'info' => t('Social SimpleSharer'),
  );
  $blocks['simplesharer_small'] = array(
    'info' => t('Social SimpleSharer Small'),
  );
  return $blocks;
}

/**
 * Implements hook_block_configure().
 */
function simplesharer_block_configure($delta = '', $settings = array(), $contexts = array()) {
  $form = array();

  if (!module_exists('libraries')) {
    backdrop_set_message(t('Libraries Module Missing. Font set libraries will not work.'), 'warning');
  } else {
    if (!(($library = libraries_load('fontawesome')) && !empty($library['loaded']))) {
      backdrop_set_message(t('Fontawesome Library Missing.'), 'warning');
    }
    if (!(($library = libraries_load('foundation')) && !empty($library['loaded']))) {
      backdrop_set_message(t('Foundation Library Missing.'), 'warning');
    }
  }

  switch ($delta) {
    case 'simplesharer':

      $form['simplesharer_style'] = array(
        '#type' => 'select',
        '#title' => t('Style'),
        '#default_value' => variable_get('simplesharer_style','social-media-standard'),
        '#description' => t("Use an optional built-in CSS style."),
        '#options' => array(
          'none' => t('None: User Provided'),
          'ideas' => t('Ideas By Elliot Style'),
          'workasone' => t('Work As One Style'),
          'social-media-standard' => t('Social Media Standard'),
          'magic-circle' => t('Magic Circle'),          
        ),
        '#required' => TRUE,
      );
      $form['simplesharer_basecolor'] = array(
        '#type' => 'textfield',
        '#title' => t('Base Color'),
        '#default_value' => variable_get('simplesharer_basecolor','#B25655'),
        '#description' => t("The hex code for the share buttons. This overrides user styles."),
        '#maxlength' => 9,
        '#size' => 20,
        '#required' => TRUE,
      );
      $form['simplesharer_linkcolor'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Color'),
        '#default_value' => variable_get('simplesharer_linkcolor','#FFFFFF'),
        '#description' => t("The hex code for the share buttons links. This overrides user styles."),
        '#maxlength' => 9,
        '#size' => 20,
        '#required' => TRUE,
      );
      $form['simplesharer_library'] = array(
        '#type' => 'select',
        '#title' => t('Library'),
        '#default_value' => variable_get('simplesharer_library','none'),
        '#description' => t('Use an optional icon library'),
        '#options' => array(
          'none' => t('None: Plain Text'),
          'fontawesome' => t('Font Awesome Icons'),
          'foundation' => t('Foundation Icon Set'),
        ),
        '#required' => TRUE,
      );
      // Facebook.
      $form['simplesharer_facebook'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Facebook'),
        '#description'    => t('Enable the Facebook Social SimpleSharer Button'),
        '#default_value'  => variable_get('simplesharer_facebook',TRUE),
      );
      // Twitter.
      $form['simplesharer_twitter'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Twitter'),
        '#description'    => t('Enable the Twitter Social SimpleSharer Button'),
        '#default_value'  => variable_get('simplesharer_twitter',TRUE),
      );
      $form['simplesharer_pinterest'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Pinterest'),
        '#description'    => t('Enable the Pinterest Social SimpleSharer Button'),
        '#default_value'  => variable_get('simplesharer_pinterest',FALSE),
      );
      $form['simplesharer_linkedin'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable LinkedIN'),
        '#description'    => t('Enable the LinkedIN Social SimpleSharer Button'),
        '#default_value'  => variable_get('simplesharer_linkedin',FALSE),
      );
      $form['simplesharer_tumblr'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Tumblr'),
        '#description'    => t('Enable the Tumblr Social SimpleSharer Button'),
        '#default_value'  => variable_get('simplesharer_tumblr',FALSE),
      );
      $form['simplesharer_reddit'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Reddit'),
        '#description'    => t('Enable the Reddot Social SimpleSharer Button'),
        '#default_value'  => variable_get('simplesharer_reddit',FALSE),
      );
      $form['simplesharer_email'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable E-mail'),
        '#description'    => t('Enable the E-mail Social SimpleSharer Button'),
        '#default_value'  => variable_get('simplesharer_email',FALSE),
      );
      break;

    case 'simplesharer_small':
      $form['simplesharer_small_library'] = array(
        '#type' => 'select',
        '#title' => t('Library'),
        '#default_value' => variable_get('simplesharer_small_library','none'),
        '#description' => t('Use an optional icon library'),
        '#options' => array(
          'none' => t('None: Plain Text'),
          'fontawesome' => t('Font Awesome Icons'),
          'foundation' => t('Foundation Icon Set'),
        ),
        '#required' => TRUE,
      );
      // Facebook.
      $form['simplesharer_small_facebook'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Facebook (sm)'),
        '#description'    => t('Enable the Facebook Social SimpleSharer (small) Button'),
        '#default_value'  => variable_get('simplesharer_small_facebook',TRUE),
      );
      // Twitter.
      $form['simplesharer_small_twitter'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Twitter (sm)'),
        '#description'    => t('Enable the Twitter Social SimpleSharer (small) Button'),
        '#default_value'  => variable_get('simplesharer_small_twitter',TRUE),
      );
      $form['simplesharer_small_pinterest'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Pinterest (sm)'),
        '#description'    => t('Enable the Pinterest Social SimpleSharer (small) Button'),
        '#default_value'  => variable_get('simplesharer_small_pinterest',FALSE),
      );
      $form['simplesharer_small_linkedin'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable LinkedIN (sm)'),
        '#description'    => t('Enable the LinkedIN Social SimpleSharer (small) Button'),
        '#default_value'  => variable_get('simplesharer_small_linkedin',FALSE),
      );
      $form['simplesharer_small_tumblr'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Tumblr (sm)'),
        '#description'    => t('Enable the Tumblr Social SimpleSharer (small) Button'),
        '#default_value'  => variable_get('simplesharer_small_tumblr',FALSE),
      );
      $form['simplesharer_small_reddit'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable Reddit (sm)'),
        '#description'    => t('Enable the Reddit Social SimpleSharer (small) Button'),
        '#default_value'  => variable_get('simplesharer_small_reddit',FALSE),
      );
      $form['simplesharer_small_email'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Enable E-mail (sm)'),
        '#description'    => t('Enable the E-mail Social SimpleSharer (small) Button'),
        '#default_value'  => variable_get('simplesharer_small_email',FALSE),
      );
      break;
  }
  return $form;
}

/**
 * Implements hook_block_save().
 */
function simplesharer_block_save($delta = '', $edit = array()) {
  switch ($delta) {
    case 'simplesharer':
      variable_set('simplesharer_style', $edit['simplesharer_style']);
      variable_set('simplesharer_basecolor', $edit['simplesharer_basecolor']);
      variable_set('simplesharer_linkcolor', $edit['simplesharer_linkcolor']);
      variable_set('simplesharer_library', $edit['simplesharer_library']);
      variable_set('simplesharer_facebook', $edit['simplesharer_facebook']);
      variable_set('simplesharer_twitter', $edit['simplesharer_twitter']);
      variable_set('simplesharer_pinterest', $edit['simplesharer_pinterest']);
      variable_set('simplesharer_linkedin', $edit['simplesharer_linkedin']);
      variable_set('simplesharer_tumblr', $edit['simplesharer_tumblr']);
      variable_set('simplesharer_reddit', $edit['simplesharer_reddit']);
      variable_set('simplesharer_email', $edit['simplesharer_email']);
      break;

    case 'simplesharer_small':
      variable_set('simplesharer_small_library', $edit['simplesharer_small_library']);
      variable_set('simplesharer_small_facebook', $edit['simplesharer_small_facebook']);
      variable_set('simplesharer_small_twitter', $edit['simplesharer_small_twitter']);
      variable_set('simplesharer_small_pinterest', $edit['simplesharer_small_pinterest']);
      variable_set('simplesharer_small_linkedin', $edit['simplesharer_small_linkedin']);
      variable_set('simplesharer_small_tumblr', $edit['simplesharer_small_tumblr']);
      variable_set('simplesharer_small_reddit', $edit['simplesharer_small_reddit']);
      variable_set('simplesharer_small_email', $edit['simplesharer_small_email']);
      break;
  }
}

/**
 * Implements hook_block_view().
 */
function simplesharer_block_view($delta = '', $settings = array(), $contexts = array()) {
  $block = array();

  switch ($delta) {
    case 'simplesharer':
      $block['content'] = simplesharer_content();
      break;

    case 'simplesharer_small':
      $block['content'] = simplesharer_small_content();
      break;
  }
  return $block;
}
