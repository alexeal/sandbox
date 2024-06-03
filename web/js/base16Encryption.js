/* *************************************************** */
/*  Encoding/decoding strings with base16.             */
/*  Created by alexeal on 04/30/2024.                  */
/*  Copyright (c) 2024 alexeal. All rights reserved.   */
/* *************************************************** */

function unicodeFromString(str){
    let unicodeArray = [];
    for(let i = 0; i < str.length; i++){
        let code = str.codePointAt(i);
        unicodeArray.push(code);
    } 
    return unicodeArray;
}

function encodeFromUnicode(array, radix) {
	let arr = [];
	for(let i = 0; i < array.length; i++){
        let code = array[i].toString(radix);
        arr.push(code);
    } 
    return arr;
}

function getEncodedString(array) {
	return array.join(' ');
}

function getEncodedArray(str) {
 	return str.split(' ');
}

function unicodeFromEncodedArray(array, radix) {
	let unicodeArray = [];
	for(let i = 0; i < array.length; i++){
        let code = parseInt(array[i], radix);
        unicodeArray.push(code);
    } 
    return unicodeArray;
}

function splitString(str) {
    let arr = [];
    for(let i=0; i< str.length; i+=2) {
        arr.push(str.substring(i, i+2));
    }
    return arr;
}

function unicodeFromEncodedString(str, radix) {
  let arr = getEncodedArray(str);
  if(arr.length === 1 && arr[0].length > 2) {
      arr = splitString(str);
  }
  return unicodeFromEncodedArray(arr, radix);
}

function stringFromUnicode(array) {
	return String.fromCodePoint(...array);
}

function encode(str, radix) {
  let unicode = unicodeFromString(str);
  let encoded = encodeFromUnicode(unicode, radix);
  return getEncodedString(encoded);
}

function decode(str, radix) {
  let unicode = unicodeFromEncodedString(str, radix);
  return stringFromUnicode(unicode);
}
