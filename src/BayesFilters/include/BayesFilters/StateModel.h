#ifndef STATEMODEL_H
#define STATEMODEL_H

#include <Eigen/Dense>

namespace bfl {
    class StateModel;
}


class bfl::StateModel
{
public:
    virtual ~StateModel() noexcept { };

    virtual void propagate(const Eigen::Ref<const Eigen::MatrixXf>& cur_states, Eigen::Ref<Eigen::MatrixXf> prop_states) = 0;

    virtual void motion(const Eigen::Ref<const Eigen::MatrixXf>& cur_states, Eigen::Ref<Eigen::MatrixXf> mot_states) = 0;

    virtual Eigen::MatrixXf getNoiseSample(const int num) = 0;

    virtual Eigen::MatrixXf getNoiseCovarianceMatrix() = 0;

    virtual bool setProperty(const std::string& property) = 0;
};

#endif /* STATEMODEL_H */
