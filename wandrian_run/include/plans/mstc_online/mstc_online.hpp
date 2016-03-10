/*
 * spiral_stc.hpp
 *
 *  Created on: Sep 15, 2015
 *      Author: manhnh
 */

#ifndef WANDRIAN_RUN_INCLUDE_PLANS_MSTC_ONLINE_MSTC_ONLINE_HPP_
#define WANDRIAN_RUN_INCLUDE_PLANS_MSTC_ONLINE_MSTC_ONLINE_HPP_

#include "../../common/vector.hpp"
#include "../base_plan.hpp"
#include "cell.hpp"
#include "communicator.hpp"

using namespace wandrian::common;

namespace wandrian {
namespace plans {
namespace mstc_online {

class MstcOnline: public BasePlan {

public:
  MstcOnline();
  ~MstcOnline();
  virtual void initialize(PointPtr, double, CommunicatorPtr);
  virtual void cover();

  void set_behavior_see_obstacle(boost::function<bool(VectorPtr, double)>);

protected:
  double tool_size; // = 'cell size' / 2
  CommunicatorPtr communicator;

  bool go_to(PointPtr, bool);
  bool see_obstacle(VectorPtr, double);
  virtual State state_of(CellPtr);
  virtual void scan(CellPtr);

private:
  CellPtr starting_cell;
  boost::function<bool(VectorPtr, double)> behavior_see_obstacle;

  bool go_with(VectorPtr, double);
};

typedef boost::shared_ptr<MstcOnline> MstcOnlinePtr;

}
}
}

#endif /* WANDRIAN_RUN_INCLUDE_PLANS_MSTC_ONLINE_MSTC_ONLINE_HPP_ */