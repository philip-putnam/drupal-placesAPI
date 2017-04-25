<?php

/**
 * @file
 * Administrative page callbacks for the nearby_places_search module.
 */

/**
 * The general settings form code stored in the $form variable.
 */
function nearby_places_search_settings_form($form, &$form_state) {
  $module_path = drupal_get_path('module', 'nearby_places_search');
  $get_default = variable_get('nearby_places_search_types', array());
  $types = array(
    'accounting' => t('Accounting'),
    'airport' => t('Airport'),
    'amusement_park' => t('Amusement park'),
    'aquarium' => t('Aquarium'),
    'art_gallery' => t('Art gallery'),
    'atm' => t('Atm'),
    'bakery' => t('Bakery'),
    'bank' => t('Bank'),
    'bar' => t('Bar'),
    'beauty_salon' => t('Beauty salon'),
    'bicycle_store' => t('Bicycle store'),
    'book_store' => t('Book store'),
    'bowling_alley' => t('Bowling alley'),
    'bus_station' => t('Bus station'),
    'cafe' => t('Cafe'),
    'campground' => t('Campground'),
    'car_dealer' => t('Car dealer'),
    'car_rental' => t('Car rental'),
    'car_repair' => t('Car repair'),
    'car_wash' => t('Car wash'),
    'casino' => t('Casino'),
    'cemetery' => t('Cemetery'),
    'church' => t('Church'),
    'city_hall' => t('City hall'),
    'clothing_store' => t('Clothing store'),
    'convenience_store' => t('Convenience store'),
    'courthouse' => t('Courthouse'),
    'dentist' => t('Dentist'),
    'department_store' => t('Department store'),
    'doctor' => t('Doctor'),
    'electrician' => t('Electrician'),
    'electronics_store' => t('Electronics store'),
    'embassy' => t('Embassy'),
    'fire_station' => t('Fire station'),
    'florist' => t('Florist'),
    'funeral_home' => t('Funeral home'),
    'furniture_store' => t('Furniture store'),
    'gas_station' => t('Gas station'),
    'grocery_or_supermarket' => t('Grocery or supermarket'),
    'gym' => t('Gym'),
    'hair_care' => t('Hair care'),
    'hardware_store' => t('Hardware store'),
    'hindu_temple' => t('Hindu temple'),
    'home_goods_store' => t('Home goods store'),
    'hospital' => t('Hospital'),
    'insurance_agency' => t('Insurance agency'),
    'jewelry_store' => t('Jewelry store'),
    'laundry' => t('Laundry'),
    'lawyer' => t('Lawyer'),
    'library' => t('Library'),
    'liquor_store' => t('Liquor store'),
    'local_government_office' => t('Local government office'),
    'locksmith' => t('Locksmith'),
    'lodging' => t('Lodging'),
    'meal_delivery' => t('Meal delivery'),
    'meal_takeaway' => t('Meal takeaway'),
    'mosque' => t('Mosque'),
    'movie_rental' => t('Movie rental'),
    'movie_theater' => t('Movie theater'),
    'moving_company' => t('Moving company'),
    'museum' => t('Museum'),
    'night_club' => t('Night club'),
    'painter' => t('Painter'),
    'park' => t('Park'),
    'parking' => t('Parking'),
    'pet_store' => t('Pet store'),
    'pharmacy' => t('Pharmacy'),
    'physiotherapist' => t('Physiotherapist'),
    'plumber' => t('Plumber'),
    'police' => t('Police'),
    'post_office' => t('Post office'),
    'real_estate_agency' => t('Real estate agency'),
    'restaurant' => t('Restaurant'),
    'roofing_contractor' => t('Roofing contractor'),
    'rv_park' => t('Rv park'),
    'school' => t('School'),
    'shoe_store' => t('Shoe store'),
    'shopping_mall' => t('Shopping mall'),
    'spa' => t('Spa'),
    'stadium' => t('Stadium'),
    'storage' => t('Storage'),
    'store' => t('Store'),
    'subway_station' => t('Subway station'),
    'synagogue' => t('Synagogue'),
    'taxi_stand' => t('Taxi stand'),
    'train_station' => t('Train station'),
    'transit_station' => t('Transit station'),
    'travel_agency' => t('Travel agency'),
    'university' => t('University'),
    'veterinary_care' => t('Veterinary care'),
    'zoo' => t('Zoo'),
  );

  $form['#attached']['css'] = array(
    $module_path . '/css/nearby_places_search.css',
  );

  $form['nearby_places_search_types'] = array(
    '#title' => t('Location Types:<br/><br/>'),
    '#type' => 'checkboxes',
    '#options' => $types,
    '#default_value' => $get_default,
    '#attributes' => array('class' => array('adm-chkbox')),
  );

  $form['nearby_places_search_auth_method'] = array(
    '#type' => 'select',
    '#title' => t('Google API Authentication Method'),
    '#description' => t('Google API Authentication Method'),
    '#default_value' => variable_get('nearby_places_search_auth_method', 1),
    '#options' => array(
      1 => t('API Key'),
      2 => t('Google Maps API for Work'),
    ),
  );

  $form['nearby_places_search_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API Key'),
    '#description' => t('Obtain a Google Maps Javascript API key at <a href="@link">@link</a>', array(
      '@link' => 'https://developers.google.com/maps/documentation/javascript/get-api-key',
    )),
    '#default_value' => variable_get('nearby_places_search_apikey', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="nearby_places_search_auth_method"]' => array('value' => 1),
      ),
    ),
  );

  $form['nearby_places_search_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API for Work: Client ID'),
    '#description' => t('For more information, visit: <a href="@link">@link</a>', array(
      '@link' => 'https://developers.google.com/maps/documentation/javascript/get-api-key#client-id',
    )),
    '#default_value' => variable_get('nearby_places_search_client_id', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="nearby_places_search_auth_method"]' => array('value' => 2),
      ),
    ),
  );

  $form['nearby_places_search_private_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API for Work: Private/Signing Key'),
    '#description' => t('For more information, visit: <a href="@link">@link</a>', array(
      '@link' => 'https://developers.google.com/maps/documentation/business/webservices/auth#how_do_i_get_my_signing_key',
    )),
    '#default_value' => variable_get('nearby_places_search_private_key', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="nearby_places_search_auth_method"]' => array('value' => 2),
      ),
    ),
  );

  $form['nearby_places_search_latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Location : Latitude'),
    '#default_value' => variable_get('nearby_places_search_latitude', '18.5204303'),
    '#size' => 40,
    '#maxlength' => 255,
    '#description' => t('The location&#39s latitude which you wish to search from'),
    '#required' => TRUE,
  );

  $form['nearby_places_search_longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Location : Longitude'),
    '#default_value' => variable_get('nearby_places_search_longitude', '73.8567436'),
    '#size' => 40,
    '#maxlength' => 255,
    '#description' => t('The location&#39s longitude which you wish to search from'),
    '#required' => TRUE,
  );

  $form['nearby_places_search_location_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Location Name'),
    '#default_value' => variable_get('nearby_places_search_location_title', 'Pune, Maharashtra, India'),
    '#size' => 40,
    '#maxlength' => 255,
    '#description' => t('The default location name for above latitude and longitude.'),
    '#required' => TRUE,
  );

  $form['nearby_places_search_radius'] = array(
    '#type' => 'textfield',
    '#title' => t('Radius'),
    '#default_value' => variable_get('nearby_places_search_radius', 1000),
    '#size' => 5,
    '#maxlength' => 5,
    '#description' => t('The radius in meters, from your search start point. Maximum is 50000.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
