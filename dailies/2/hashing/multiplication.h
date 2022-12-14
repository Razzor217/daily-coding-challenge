/**
 * @file multiplication.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of multiplicative hashing
 * @version 0.1
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HASHING_FUNCTION_MULTIPLICATION_HEADER
#define HASHING_FUNCTION_MULTIPLICATION_HEADER


#include <cstdint>
#include <cmath>

#include <hashing/function.h>


namespace hashing
{

    /**
     * @brief Multiplicative hashing method
     *
     * Let \f$0<a<1\f$ and \f$m\in\mathbb{N}\f$.
     * Then \f$h(k) = \lfloor m (kA \mod 1) \rfloor\f$.
     *
     * Let \f$s,w\in\mathbb{R}\f$, s.t. \f$a=\frac{s}{w}\f$.
     * Then
     * \f[
     *   h(k) =
     *     \left\lfloor
     *       m \frac{ks \mod w}{w}
     *     \right\rfloor
     * \f]
     *
     * @tparam Key The hashed key type
     * @tparam M Upper bound for hash values
     * @tparam S See definition of \f$h(k)\f$
     * @tparam W See definition of \f$h(k)\f$
     */
    template <
        typename Key = std::uint32_t,
        std::uint32_t M = 1024,
        std::uint64_t S = 2654435769,
        std::uint64_t W = 4294967296>
    class multiplication : public virtual function<Key, Key>
    {
    public:
        static_assert(M > 0);
        static_assert(W > 0);
        static_assert(static_cast<double>(S) / static_cast<double>(W) > 0);
        static_assert(static_cast<double>(S) / static_cast<double>(W) < 1);

        using key_type = typename function<Key, Key>::key_type;
        using size_type = typename function<Key, Key>::size_type;

        /// @see function::operator()()
        size_type
        operator() (key_type const& key) const override
        {
            double const k {static_cast<double>(key)};
            return static_cast<std::uint32_t>(std::floor((m * std::fmod(k * s, w)) / w));
        }

    private:
        static constexpr double const m {static_cast<double>(M)};
        static constexpr double const s {static_cast<double>(S)};
        static constexpr double const w {static_cast<double>(W)};
    };


    /**
     * @brief Specialization of @ref multiplication where \f$m=2^M\f$ and \f$w=2^32\f$
     *
     * @tparam Key The hashed key type
     * @tparam M Log2 of upper bound for hash values
     * @tparam S See definition of \f$h(k)\f$
     */
    template <
        typename Key = std::uint32_t,
        std::uint32_t M = 10,
        std::uint64_t S = 2654435769>
    class multiplication_shift : public virtual function<Key, Key>
    {
    public:
        static_assert(M > 0);
        static_assert(static_cast<double>(S) / 4294967296.0 > 0);
        static_assert(static_cast<double>(S) / 4294967296.0 < 1);

        using key_type = typename function<Key, Key>::key_type;
        using size_type = typename function<Key, Key>::size_type;

        /// @see function::operator()()
        size_type
        operator() (key_type const& key) const override
        {
            std::uint64_t const k {static_cast<std::uint64_t>(key)};
            return (S * k & 0x00000000FFFFFFFF) >> (w - M);
        }

    private:
        static constexpr std::uint32_t const w {32U};
    };


    /**
     * @brief Specialization of @ref multiplication_shift with XOR correction
     *
     * @tparam Key The hashed key type
     * @tparam M Log2 of upper bound for hash values
     * @tparam S See definition of \f$h(k)\f$
     */
    template <
        typename Key = std::uint32_t,
        std::uint32_t M = 10,
        std::uint64_t S = 2654435769>
    class multiplication_shift_xor : public virtual function<Key, Key>
    {
    public:
        static_assert(M > 0);
        static_assert(static_cast<double>(S) / 4294967296.0 > 0);
        static_assert(static_cast<double>(S) / 4294967296.0 < 1);

        using key_type = typename function<Key, Key>::key_type;
        using size_type = typename function<Key, Key>::size_type;

        /// @see function::operator()()
        size_type
        operator() (key_type const& key) const override
        {
            std::uint64_t k {static_cast<std::uint64_t>(key)};
            k ^= k >> (w - M);
            return (S * k & 0x00000000FFFFFFFF) >> (w - M);
        }

    private:
        static constexpr std::uint32_t const w {32U};
    };

} // !namespace hashing

#endif // !HASHING_FUNCTION_MULTIPLICATION_HEADER
