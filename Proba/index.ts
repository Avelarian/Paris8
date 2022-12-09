/** QUANTILE FUNCTION */

let F: number;
let u: number;
let b: number;

const quantile = (
  independentFunction: number,
  dependentVariable: number,
  constant: number
) => {
  if (independentFunction <= 0.5) {
    return dependentVariable + constant * Math.log(2 * independentFunction);
  } else {
    return dependentVariable - constant * Math.log(2 - 2 * independentFunction);
  }
};

/** REALIZATIONS FUNCTION */

const realization = (realizationsLength: number) => {
  for (let index = 0; index < realizationsLength; index++) {
    F = Math.random.
  }
};
