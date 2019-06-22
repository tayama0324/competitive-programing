typedef long double Double;

const Double eps = 1e-18;

bool eq(Double a, Double b) { return fabs(a - b) < eps; }

// max(abs_error, rel_error)
Double error(Double a, Double b) {
  Double abs_error = fabs(a - b);
  if (a > eps) { return min(abs_error, abs_error / a); }
  return abs_error;
}

