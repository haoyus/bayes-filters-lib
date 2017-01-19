#ifndef VISUALCORRECTION_H
#define VISUALCORRECTION_H

#include <Eigen/Dense>
#include <opencv2/core/core.hpp>


namespace bfl
{

    class VisualCorrection
    {
    public:
        virtual ~VisualCorrection() noexcept { };

        virtual void correct(const Eigen::Ref<const Eigen::VectorXf>& pred_state, cv::InputArray measurements, Eigen::Ref<Eigen::VectorXf> cor_state) = 0;

        virtual void innovation(const Eigen::Ref<const Eigen::VectorXf>& pred_state, cv::InputArray measurements, Eigen::Ref<Eigen::MatrixXf> innovation) = 0;

        virtual void likelihood(const Eigen::Ref<const Eigen::MatrixXf>& innovation, Eigen::Ref<Eigen::VectorXf> cor_state) = 0;
    };
    
} // namespace bfl

#endif /* VISUALCORRECTION_H */
