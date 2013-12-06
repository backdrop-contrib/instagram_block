<?php

/**
 * @file
 * Contains forms and pages for instagram admin pages.
 */

/**
 * Form for authenticating user with Instagram API.
 */
function instagram_block_admin_settings($form, &$form_state) {
  $form = array();

  $content = t('To configure your instagram account you need to authorise your account. To do this, click ');
  $path = 'https://instagram.com/oauth/authorize/';
  $options = array(
    'query' => array(
      'client_id' => '759ec610e0c1416baa8a8a6b41552087',
      'redirect_uri' => 'http://instagram.yanniboi.com/configure/instagram',
      'response_type' => 'code',
    ),
    'attributes' => array(
      'target' => '_blank',
    ),
  );

  $content .= l(t('here'), $path, $options);
  $content .= '.';

  $form['authorise'] = array(
    '#markup' => $content,
  );

  // Create a keyed array of blank defaults for the storage variable.
  $empty = array(
    'user_id' => '',
    'access_token' => '',
    'count' => '4',
    'width' => '100',
    'height' => '100',
    'img_resolution' => 'thumbnail',
  );

  // Store data from variable in $form for now.
  $form['#data'] = variable_get('instagram_block_data', $empty);

  $form['user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('User Id'),
    '#description' => t('Your unique Instagram user id. Eg. 460786510'),
    '#default_value' => isset($form['#data']['user_id']) ? $form['#data']['user_id'] : '',
  );

  $form['access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Access Token'),
    '#description' => t('Your Instagram access token. Eg. 460786509.ab103e5.a54b6834494643588d4217ee986384a8'),
    '#default_value' => isset($form['#data']['access_token']) ? $form['#data']['access_token'] : '',
  );

  $form['count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of images to display.'),
    '#default_value' => isset($form['#data']['count']) ? $form['#data']['count'] : '',
  );

  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Image width in pixels.'),
    '#default_value' => isset($form['#data']['width']) ? $form['#data']['width'] : '',
  );

  $form['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Image height in pixels.'),
    '#default_value' => isset($form['#data']['height']) ? $form['#data']['height'] : '',
  );

  $image_options = array(
    'thumbnail' => t('Thumbnail Preview'),
    'low_resolution' => t('Low Resolution'),
    'standard_resolution' => t('Standard Resolution'),
  );

  $form['img_resolution'] = array(
    '#type' => 'select',
    '#title' => t('Image resolution'),
    '#description' => t('Choose the quality of the images you would like to display.'),
    '#options' => $image_options,
    '#default_value' => isset($form['#data']['img_resolution']) ? $form['#data']['img_resolution'] : '',
  );

  $form['#validate'][] = 'instagram_block_admin_settings_validate';
  $form['#submit'][] = 'instagram_block_admin_settings_submit';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}


/**
 * Form validation handler.
 */
function instagram_block_admin_settings_validate(&$form, &$form_state) {
  // @todo: Do some validation.
}

/**
 * Form submission handler.
 */
function instagram_block_admin_settings_submit(&$form, &$form_state) {
  if (isset($form_state['values'])) {
    variable_set('instagram_block_data', $form_state['values']);
    drupal_set_message(t('Instagram block configuration has been saved.'), 'status');
  }
}
