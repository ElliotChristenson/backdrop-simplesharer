<?php

define('DEFAULT_BASECOLOR', '#B25655');
define('DEFAULT_LINKCOLOR', '#FFFFFF');

/**
 * Implements hook_theme().
 */
function simplesharer_theme() {
  $module_path = backdrop_get_path('module', 'simplesharer');
  return array(
    'simplesharer_symbol_button' => array(
      'variables' => array(
        'buttonname' => NULL,
        'textname' => NULL,
        'titletext' => NULL,
        'url' => NULL,
      ),
      'template' => 'simplesharer-symbol-button',
      'path' => $module_path . '/templates',
    ),
    'simplesharer_color_css' => array(
      'variables' => array(
        'simplesharer_basecolor' => NULL,
        'simplesharer_linkcolor' => NULL,
        'simplesharer_topcolor' => NULL,
        'simplesharer_bottomcolor' => NULL,
        'simplesharer_shadowcolor' => NULL,
      ),
      'template' => 'simplesharer-color-css',
      'path' => $module_path . '/templates',
    ),
    'simplesharer' => array(
      'variables' => array(
        'simplesharer_color_css' => NULL,
        'simplesharer_facebook' => NULL,
        'simplesharer_twitter' => NULL,
        'simplesharer_pinterest' => NULL,
        'simplesharer_linkedin' => NULL,
        'simplesharer_tumblr' => NULL,
        'simplesharer_reddit' => NULL,
        'simplesharer_email' => NULL,
      ),
      'template' => 'simplesharer',
      'path' => $module_path . '/templates',
    ),
    'simplesharer_small_button' => array(
      'variables' => array(
        'buttonname' => NULL,
        'textname' => NULL,
        'titletext' => NULL,
        'url' => NULL,
      ),
      'template' => 'simplesharer-small-button',
      'path' => $module_path . '/templates',
    ),
    'simplesharer_small' => array(
      'variables' => array(
        'simplesharer_small_facebook' => NULL,
        'simplesharer_small_twitter' => NULL,
        'simplesharer_small_pinterest' => NULL,
        'simplesharer_small_linkedin' => NULL,
        'simplesharer_small_tumblr' => NULL,
        'simplesharer_small_reddit' => NULL,
        'simplesharer_small_email' => NULL,
      ),
      'template' => 'simplesharer-small',
      'path' => $module_path . '/templates',
    ),
  );
}

/**
 * Custom function to change the level of the color
 *
 * @return string
 *
 *   returns a CSS hex code
 */
 function simplesharer_colorlevel($color,$level) {
   $red = dechex( (int) (hexdec(substr($color,1,2))) * $level);
   $green = dechex( (int) (hexdec(substr($color,3,2))) * $level);
   $blue = dechex( (int) (hexdec(substr($color,5,2))) * $level);
   $newcolor = "#".$red.$green.$blue;
   return $newcolor;
 }

/**
 * Custom function to assemble renderable array for block content.
 *
 * @return array
 *
 *   returns a renderable array of block content.
 */
function simplesharer_content() {
  $block = array();
  $icon_library = simplesharer_iconlibrary('simplesharer');
  $icon_library = isset($icon_library) ? $icon_library : 'none';
  $full_url = backdrop_encode_path($GLOBALS['base_url'] . request_uri());
  $logo = backdrop_encode_path(theme_get_setting('logo'));
  $site_name = variable_get('site_name');
  $title = rawurlencode($site_name . ' : ' . backdrop_get_title());

  $large_style = variable_get('simplesharer_style');
  $large_style = isset($large_style) ? $large_style : 'social-media-standard';

  $basecolor = variable_get('simplesharer_basecolor');
  $basecolor = isset($basecolor) ? $basecolor : DEFAULT_BASECOLOR;
  $basecolor = variable_get('simplesharer_basecolor');
  $basecolor = isset($basecolor) ? $basecolor : DEFAULT_BASECOLOR;
  $linkcolor = variable_get('simplesharer_linkcolor');
  $linkcolor = isset ($linkcolor) ? $linkcolor : DEFAULT_LINKCOLOR;
  $topcolor = simplesharer_colorlevel($basecolor,1.3);
  $bottomcolor = simplesharer_colorlevel($basecolor,0.7);
  $shadowcolor = simplesharer_colorlevel($basecolor,0.5);

  $facebook = variable_get('simplesharer_facebook');
  $facebook = isset($facebook) ? $facebook : TRUE;
  $twitter = variable_get('simplesharer_twitter');
  $twitter = isset($twitter) ? $twitter : TRUE;
  $pinterest = variable_get('simplesharer_pinterest');
  $linkedin = variable_get('simplesharer_linkedin');
  $tumblr = variable_get('simplesharer_tumblr');
  $reddit = variable_get('simplesharer_reddit');
  $email = variable_get('simplesharer_email');
  $facebook_button = NULL;
  $twitter_button = NULL;
  $pinterest_button = NULL;
  $linkedin_button = NULL;
  $tumblr_button = NULL;
  $reddit_button = NULL;
  $email_button = NULL;
  $color_css = NULL;

  $markup_content = '';

  if ($basecolor && $linkcolor && $topcolor && $bottomcolor && $shadowcolor && $large_style != 'none') {
    $color_css = theme('simplesharer_color_css', array(
      'simplesharer_basecolor'           => $basecolor,
      'simplesharer_linkcolor'           => $linkcolor,
      'simplesharer_topcolor'            => $topcolor,
      'simplesharer_bottomcolor'         => $bottomcolor,
      'simplesharer_shadowcolor'         => $shadowcolor,
    ));
  }
  if ($facebook) {
    $facebook_button = theme('simplesharer_symbol_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'facebook',
      'awesomename'         => 'fa-facebook',
      'foundationname'      => 'fi-social-facebook',
      'titletext'           => 'Facebook',
      'url'                 => 'https://www.facebook.com/sharer/sharer.php?u=' . $full_url,
      'actiontext'          => 'share',
    ));
  }
  if ($twitter) {
    $twitter_button = theme('simplesharer_symbol_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'twitter',
      'awesomename'         => 'fa-twitter',
      'foundationname'      => 'fi-social-twitter',
      'titletext'           => 'Twitter',
      'url'                 => 'https://twitter.com/intent/tweet/?url=' . $full_url . '&text=' . $title,
      'actiontext'          => 'tweet',
    ));
  }
  if ($pinterest) {
    $pinterest_button = theme('simplesharer_symbol_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'pinterest',
      'awesomename'         => 'fa-pinterest',
      'foundationname'      => 'fi-social-pinterest',
      'titletext'           => 'Pinterest',
      'url'                 => 'https://www.pinterest.com/pin/create/button/?url=' . $full_url .
        '&media=' . $logo . '&description=' . $title,
      'actiontext'          => 'pin',
    ));
  }
  if ($linkedin) {
    $linkedin_button = theme('simplesharer_symbol_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'linkedin',
      'awesomename'         => 'fa-linkedin',
      'foundationname'      => 'fi-social-linkedin',
      'titletext'           => 'LinkedIN',
      'url'                 => 'https://www.linkedin.com/shareArticle?mini=true&url=' . $full_url,
      'actiontext'          => 'share',
    ));
  }
  if ($tumblr) {
    $tumblr_button = theme('simplesharer_symbol_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'tumblr',
      'awesomename'         => 'fa-tumblr',
      'foundationname'      => 'fi-social-tumblr',
      'titletext'           => 'Tumblr',
      'url'                 => 'https://www.tumblr.com/share/link?url=' . $full_url,
      'actiontext'          => 'blog',
    ));
  }
  if ($reddit) {
    $reddit_button = theme('simplesharer_symbol_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'reddit',
      'awesomename'         => 'fa-reddit',
      'foundationname'      => 'fi-social-reddit',
      'titletext'           => 'Reddit',
      'url'                 => 'https://www.reddit.com/submit?url=' . $full_url,
      'actiontext'          => 'submit',
    ));
  }
  if ($email) {
    $email_button = theme('simplesharer_symbol_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'email',
      'awesomename'         => 'fa-envelope',
      'foundationname'      => 'fi-mail',
      'titletext'           => 'E-mail',
      'url'                 => 'mailto:?subject=' . $title .
        '&body=' . $title . "%20:%20" . $full_url,
      'actiontext'          => 'send',
    ));
  }
  $markup_content = theme('simplesharer', array(
    'simplesharer_color_css'         => $color_css,
    'simplesharer_facebook_button'   => $facebook_button,
    'simplesharer_twitter_button'    => $twitter_button,
    'simplesharer_pinterest_button'  => $pinterest_button,
    'simplesharer_linkedin_button'   => $linkedin_button,
    'simplesharer_tumblr_button'     => $tumblr_button,
    'simplesharer_reddit_button'     => $reddit_button,
    'simplesharer_email_button'      => $email_button,
  ));

  $block = array(
    'content'     => array(
      '#type'     => 'markup',
      '#markup'   => $markup_content,
      '#suffix'   => '',
    ),
  );

  if ((isset($large_style)) && ($large_style != 'none')) {
    $block['content']['#attached']['css'][] = backdrop_get_path('module', 'simplesharer') .
    '/css/' . $large_style . '.css';
  }

  return $block;
}

/**
 * Custom function to assemble renderable array for block content.
 *
 * @return array
 *   returns a renderable array of block content.
 */
function simplesharer_small_content() {
  $block = array();
  $icon_library = simplesharer_iconlibrary('simplesharer_small');
  $full_url = backdrop_encode_path($GLOBALS['base_url'] . request_uri());
  $logo = backdrop_encode_path(theme_get_setting('logo'));
  $title = rawurlencode('Ideas By Elliot : ' . backdrop_get_title());

  $facebook = variable_get('simplesharer_small_facebook') ?: TRUE;
  $twitter = variable_get('simplesharer_small_twitter') ?: TRUE;
  $pinterest = variable_get('simplesharer_small_pinterest') ?: FALSE;
  $linkedin = variable_get('simplesharer_small_linkedin') ?: FALSE;
  $tumblr = variable_get('simplesharer_small_tumblr') ?: FALSE;
  $reddit = variable_get('simplesharer_small_reddit') ?: FALSE;
  $email = variable_get('simplesharer_small_email') ?: FALSE;
  $facebook_button = NULL;
  $twitter_button = NULL;
  $pinterest_button = NULL;
  $linkedin_button = NULL;
  $tumblr_button = NULL;
  $reddit_button = NULL;
  $email_button = NULL;

  $markup_content = '';
  if ($facebook) {
    $facebook_button = theme('simplesharer_small_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'facebook',
      'awesomename'         => 'fa-facebook',
      'foundationname'      => 'fi-social-facebook',
      'titletext'           => 'Facebook',
      'url'                 => 'https://www.facebook.com/sharer/sharer.php?u=' . $full_url,
      'actiontext'          => 'share',
    ));
  }
  if ($twitter) {
    $twitter_button = theme('simplesharer_small_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'twitter',
      'awesomename'         => 'fa-twitter',
      'foundationname'      => 'fi-social-twitter',
      'titletext'           => 'Twitter',
      'url'                 => 'https://twitter.com/intent/tweet/?url=' . $full_url .
        '&text=' . $title,
      'actiontext'          => 'tweet',
    ));
  }
  if ($pinterest) {
    $pinterest_button = theme('simplesharer_small_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'pinterest',
      'awesomename'         => 'fa-pinterest',
      'foundationname'      => 'fi-social-pinterest',
      'titletext'           => 'Pinterest',
      'url'                 => 'https://www.pinterest.com/pin/create/button/?url=' . $full_url .
      '&media=' . $logo .
      '&description=' . $title,
      'actiontext'  => 'pin',
    ));
  }
  if ($linkedin) {
    $linkedin_button = theme('simplesharer_small_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'linkedin',
      'awesomename'         => 'fa-linkedin',
      'foundationname'      => 'fi-social-linkedin',
      'titletext'           => 'LinkedIN',
      'url'                 => 'https://www.linkedin.com/shareArticle?mini=true&url=' . $full_url,
      'actiontext'          => 'share',
    ));
  }
  if ($tumblr) {
    $tumblr_button = theme('simplesharer_small_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'tumblr',
      'awesomename'         => 'fa-tumblr',
      'foundationname'      => 'fi-social-tumblr',
      'titletext'           => 'Tumblr',
      'url'                 => 'https://www.tumblr.com/share/link?url=' . $full_url,
      'actiontext'          => 'blog',
      ));
  }
  if ($reddit) {
    $reddit_button = theme('simplesharer_small_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'reddit',
      'awesomename'         => 'fa-reddit',
      'foundationname'      => 'fi-social-reddit',
      'titletext'           => 'Reddit',
      'url'                 => 'https://www.reddit.com/submit?url=' . $full_url,
      'actiontext'          => 'submit',
    ));
  }
  if ($email) {
    $email_button = theme('simplesharer_small_button', array(
      'iconlibrary'         => $icon_library,
      'buttonname'          => 'email',
      'awesomename'         => 'fa-envelope',
      'foundationname'      => 'fi-social-smail',
      'titletext'           => 'E-mail',
      'url'                 => 'mailto:?subject=' . $title .
      '&body=' . $title . "%20:%20" . $full_url,
      'actiontext'          => 'send',
    ));
  }
  $markup_content = theme('simplesharer_small', array(
    'simplesharer_small_facebook_button'   => $facebook_button,
    'simplesharer_small_twitter_button'    => $twitter_button,
    'simplesharer_small_pinterest_button'  => $pinterest_button,
    'simplesharer_small_linkedin_button'   => $linkedin_button,
    'simplesharer_small_tumblr_button'     => $tumblr_button,
    'simplesharer_small_reddit_button'     => $reddit_button,
    'simplesharer_small_email_button'      => $email_button,
  ));

  // Block output in HTML with div wrapper.
  $block = array(
    'message'   => array(
      '#type'   => 'markup',
      '#markup' => $markup_content,
      '#suffix' => '',
    ),
  );

  return $block;
}
