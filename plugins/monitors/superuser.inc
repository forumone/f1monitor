<?php

// TODO check email for superuser follows pattern support+sitename@forumone.com ?
//This is only for clients who are using F1 managed hosting though. so we would need to figure out a way of detecting this.


$plugin = array(
  //'callback' => 'f1monitor_superuser',
);

/**
 * Check whether caching is turned on and return a structure as expected of hook_requirements().
 */
function f1monitor_superuser() {
  $superuser = TRUE;

  $pos_desciption = t('Superuser account settings matches the standard definition.');
  $neg_description = t('Superuser account settings not standard.');

  $requirement = array(
    'title' => t('Cache pages for Anonymous users.'),
    'value' => $superuser ? t('Enabled') : t('Disabled'),
    'description' => $superuser ? $pos_desciption : $neg_description,
    'severity' => $superuser ? REQUIREMENT_OK : REQUIREMENT_WARNING,
  );

  return array(
    'f1monitor_caching' => $requirement,
  );
}
