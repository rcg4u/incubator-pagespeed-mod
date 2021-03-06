/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */


#ifndef PAGESPEED_KERNEL_HTML_HTML_TESTING_PEER_H_
#define PAGESPEED_KERNEL_HTML_HTML_TESTING_PEER_H_

#include <cstddef>

#include "pagespeed/kernel/base/basictypes.h"
#include "pagespeed/kernel/html/html_element.h"
#include "pagespeed/kernel/html/html_node.h"
#include "pagespeed/kernel/html/html_parse.h"

namespace net_instaweb {

class HtmlEvent;

class HtmlTestingPeer {
 public:
  HtmlTestingPeer() { }

  static void SetNodeParent(HtmlNode* node, HtmlElement* parent) {
    node->set_parent(parent);
  }
  static void AddEvent(HtmlParse* parser, HtmlEvent* event) {
    parser->AddEvent(event);
  }
  static void SetCurrent(HtmlParse* parser, HtmlNode* node) {
    parser->SetCurrent(node);
  }
  static void set_coalesce_characters(HtmlParse* parser, bool x) {
    parser->set_coalesce_characters(x);
  }
  static size_t symbol_table_size(HtmlParse* parser) {
    return parser->symbol_table_size();
  }
  static void set_buffer_events(HtmlParse* parse, bool value) {
    parse->set_buffer_events(value);
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(HtmlTestingPeer);
};

}  // namespace net_instaweb

#endif  // PAGESPEED_KERNEL_HTML_HTML_TESTING_PEER_H_
