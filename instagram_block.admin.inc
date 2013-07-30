<?php

/**
 * @file.
 *
 * Contains forms and pages for instagram admin pages.
 */

/**
 * Form for authenticating user with Instagram API.
 */
function instagram_block_admin_settings($form, &$form_state) {
  $form = array();

  $content = 'To configure your instagram account you need to authorise your account. To do this, click ';
  $path = 'https://instagram.com/oauth/authorize/';
  $options = array(
    'query' => array(
      'client_id' => '759ec610e0c1416baa8a8a6b41552087',
      'redirect_uri' => 'http://yanniboi.com/admin/configure/instagram',
      'response_type' => 'code',
    ),
  );
  $content .= l('here', $path, $options);

  $form['authorise'] = array(
    '#markup' => $content,
  );

  $form['test'] = array('#markup' => 'Test');

  return $form;
}

/**
 * Redirect page from the authentication process.
 */
function instagram_block_authorise_page() {
  $url = "https://api.instagram.com/oauth/access_token";
  $access_token_parameters = array(
    'client_id'	=> '759ec610e0c1416baa8a8a6b41552087',
    'client_secret' => 'fe74f2686c3d42deae29e59aafda2e74',
    'grant_type' => 'authorization_code',
    'redirect_uri' => 'http://yanniboi.com/admin/configure/instagram',
    'code' => $_GET["code"],
  );

  $curl = curl_init($url);
  curl_setopt($curl,CURLOPT_POST,true);
  curl_setopt($curl,CURLOPT_POSTFIELDS,$access_token_parameters);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
  $result = curl_exec($curl);

  $user_id = '1234';
  $access_code = '1234';

  $content = array(
    'user_id' => array(
      '#markup' => 'Your user id is: ' . $user_id . '</br>',
    ),
    'access_code' => array(
      '#markup' => 'Your access code is: ' . $access_code,
    ),
  );

  return $content;
}
