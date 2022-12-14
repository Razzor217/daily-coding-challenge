/**
 * @file identity.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of identity hash function
 * @version 0.1
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HASHING_FUNCTION_IDENTITY_HEADER
#define HASHING_FUNCTION_IDENTITY_HEADER


#include <hashing/function.h>


namespace hashing
{

    /**
     * @brief Identity hash function
     *
     * @tparam Key The hashed key type
     */
    template <typename Key = std::size_t>
    class identity : public virtual function<Key, Key>
    {
    public:
        using key_type = typename function<Key, Key>::key_type;
        using size_type = typename function<Key, Key>::size_type;

        /// @see function::operator()()
        size_type
        operator() (key_type const& key) const override
        {
            return key;
        }
    };

} // !namespace hashing


#endif // !HASHING_FUNCTION_IDENTITY_HEADER
