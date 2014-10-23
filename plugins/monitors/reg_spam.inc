<?php

// TODO check for large numbers of blocked users that could be spam
//$items['f1monitor_user_spam'] = array();


$plugin = array(
  //'callback' => 'f1monitor_user_registration_spam'
);

/**
 * Check whether caching is turned on and return a structure as expected of hook_requirements().
 */
function f1monitor_user_registration_spam() {

  $spam = f1monitor_determine_user_reg_spam();

  $pos_desciption = t('User registrations look normal.');
  $neg_description = t('Large numbers of unauthenticated users are being created.');

  $requirement = array(
    'title' => t('User registration spam.'),
    'value' => $spam ? t('Normal') : t('Concern'),
    'description' => $spam ? $pos_desciption : $neg_description,
    'severity' => $spam ? REQUIREMENT_OK : REQUIREMENT_WARNING,
  );

  return null;

  return array(
    'f1monitor_user_registration_spam' => $requirement,
  );
}


/**
 * Determines if the site currently has suspected user registration spam.
 */
function f1monitor_determine_user_reg_spam() {
  //Requirements to be considered user registration spam.
    //More than 1 new account created per day.
    //At least 90% of new accounts created in the previous 30 days are disabled.
    //TODO Ceeate monitoring plugin that checks that new user accounts are disabled automatically.

  return true;
}