<?php

/**
 * Implements hook_views_data().
 */

function mconnect_views_data()
{

  $data = array();

  $data['mconnect_data']['table']['group'] = t('Mconnect');
  $data['mconnect_data']['table']['base'] = array(
      'field' => 'uid',
      'title' => t('Mconnect'),
      'help' => t('Contains rows of feeds.'),
  );

  $data['mconnect_data']['table']['join'] = array(
    'node' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // The ID field
  $data['mconnect_data']['id'] = array(
    'title' => t('ID'),
    'help' => t('The record ID.'),
    'field' => array(
        'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['mconnect_data']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('References to a user.'),
    'relationship' => array(
      'base' => 'users', // The name of the table to join with.
      'base field' => 'uid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('User relationship'),
      'label' => t('User relationship'),
      'label' => t('User relationship'),
    ),
  );

  $data['mconnect_data']['provider'] = array(
    'title' => t('Provider'),
    'help' => t('Feed provider.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['mconnect_data']['feed_id'] = array(
    'title' => t('Feed ID'),
    'help' => t('Feed ID.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['mconnect_data']['data'] = array(
    'title' => t('Feed Data'),
    'help' => t('Feed Data.'),
    'field' => array(
      'handler' => 'views_handler_field',
    )
  );

  $data['mconnect_data']['cron_date'] = array(
    'title' => t('Cron Date'),
    'help' => t('Cron Date.'),
    'field' => array(
      'handler' => 'views_handler_field',
    )
  );

  $data['mconnect_data']['created'] = array(
    'title' => t('Created Date'),
    'help' => t('Created Date.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['mconnect_data']['updated'] = array(
    'title' => t('Updated Date'),
    'help' => t('Updated Date.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );


  $data['mconnect_tag']['table']['group'] = t('Mconnect');
  $data['mconnect_tag']['table']['join'] = array(
     // Directly links to node table.
    'mconnect_data' => array(
      'table' => 'mconnect_tag',
      'left_field' => 'feed_id',
      'field' => 'feed_id'
    ),
  );
  $data['mconnect_data']['tid'] = array(
    'title' => t('Tag ID'),
    'help' => t('The record ID.'),
    'field' => array(
        'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['mconnect_tag']['tag'] = array(
    'title' => t('Tag name'),
    'help' => t('Tag name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;

}

