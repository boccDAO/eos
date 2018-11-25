/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosio/chain_plugin/chain_plugin.hpp>
#include <appbase/application.hpp>
#include <memory>

namespace eosio {

using bocc_mongo_db_plugin_impl_ptr = std::shared_ptr<class bocc_mongo_db_plugin_impl>;

/**
 * Provides persistence to MongoDB for:
 * accounts
 * actions
 * block_states
 * blocks
 * transaction_traces
 * transactions
 * pub_keys
 * account_controls
 *
 *   See data dictionary (DB Schema Definition - EOS API) for description of MongoDB schema.
 *
 *   If cmake -DBUILD_bocc_mongo_db_plugin=true  not specified then this plugin not compiled/included.
 */
class bocc_mongo_db_plugin : public plugin<bocc_mongo_db_plugin> {
public:
   APPBASE_PLUGIN_REQUIRES((chain_plugin))

   bocc_mongo_db_plugin();
   virtual ~bocc_mongo_db_plugin();

   virtual void set_program_options(options_description& cli, options_description& cfg) override;

   void plugin_initialize(const variables_map& options);
   void plugin_startup();
   void plugin_shutdown();

private:
   bocc_mongo_db_plugin_impl_ptr my;
};

}

