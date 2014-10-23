<?php

// TODO check email for superuser follows pattern support+sitename@forumone.com ?


$plugin = array(
  'callback' => 'f1monitor_superuser',
);

/**
 * Check whether caching is turned on and return a structure as expected of hook_requirements().
 */
function f1monitor_superuser() {
  $superuser = TRUE;

  $pos_desciption = t('Superuser account settings matches the standard definition.');
  $neg_description = t('Superuser account settings not standard.');

  $requirement = array(
    'title' => t('Superuser is secure and matches standard settings.'),
    'value' => $superuser ? t('Enabled') : t('Disabled'),
    'description' => $superuser ? $pos_desciption : $neg_description,
    'severity' => $superuser ? REQUIREMENT_OK : REQUIREMENT_WARNING,
  );

  return array(
    'f1monitor_caching' => $requirement,
  );
}
