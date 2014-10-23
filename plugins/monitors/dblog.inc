<?php

$plugin = array(
  'callback' => 'f1monitor_dblog_is_on',
);

/**
 * Check whether caching is turned on and return a structure as expected of hook_requirements().
 */
function f1monitor_dblog_is_on() {
  $dblog = module_exists('dblog');

  $pos_desciption = t('The Database Logging module is Enabled. Disable in production to improve performance.');
  $neg_description = t('Database logging is disabled.');

  $requirement = array(
    'title' => t('Database logging module.'),
    'value' => $dblog ? t('Enabled') : t('Disabled'),
    'description' => $dblog ? $pos_desciption : $neg_description,
    'severity' => !$dblog ? REQUIREMENT_OK : REQUIREMENT_WARNING,
  );

  return array(
    'f1monitor_dblog' => $requirement,
  );
}
