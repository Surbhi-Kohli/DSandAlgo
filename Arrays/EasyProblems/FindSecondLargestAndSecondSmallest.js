/*
Problem Statement: Given an array, find the second smallest and second largest element in the array.
Print ‘-1’ in the event that either of them doesn’t exist.
*/

function secondSmallest(arr) {
  if (arr.length < 2)
    return -1;

  let small = Infinity;
  let second_small = Infinity;

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < small) {
      second_small = small;
      small = arr[i];
    } else if (arr[i] < second_small && arr[i] !== small) {
      second_small = arr[i];
    }
  }

  return second_small;
}

function secondLargest(arr) {
  if (arr.length < 2)
    return -1;

  let large = -Infinity;
  let second_large = -Infinity;

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > large) {
      second_large = large;
      large = arr[i];
    } else if (arr[i] > second_large && arr[i] !== large) {
      second_large = arr[i];
    }
  }

  return second_large;
}

const arr = [1, 2, 4, 7, 7, 5];
const sS = secondSmallest(arr);
const sL = secondLargest(arr);

console.log("Second smallest is " + sS);
console.log("Second largest is " + sL);
