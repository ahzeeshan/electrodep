
#ifndef NMAGNITUDEVECCONSTRAINTLAGRANGE_H
#define NMAGNITUDEVECCONSTRAINTLAGRANGE_H

#include "Kernel.h"
//*#include "DerivativeMaterialInterface.h"
#include "NonlinearSystem.h"

// Forward Declarations
class NMagnitudeVecConstraintLagrange;

template <>
InputParameters validParams<NMagnitudeVecConstraintLagrange>();

/**
 * NMagnitudeVecConstraintLagrange is a constraint kernel that acts on the
 * lambda lagrange multiplier non-linear variables to
 * enforce \f$ \sum_n h_i(\eta_i) - \epsilon\lambda \equiv 1 \f$.
 */
class NMagnitudeVecConstraintLagrange : public Kernel
{
public:
  NMagnitudeVecConstraintLagrange(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int);

  Real _epsilon;
  const VectorVariableValue & _vec;
  unsigned _vec_id;
};

#endif // NMAGNITUDEVECCONSTRAINTLAGRANGE_H