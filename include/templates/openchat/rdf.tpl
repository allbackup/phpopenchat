<rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
         xmlns:dc="http://purl.org/dc/elements/1.1/"
         xmlns:wn="http://xmlns.com/wordnet/1.6/"
         xmlns:foaf="http://xmlns.com/foaf/0.1/">

  <foaf:Agent rdf:about="http://phpopenchat.org/">
    <foaf:topic><?=$TEMPLATE_OUT['chat_name']?></foaf:topic>
    <dc:language><?=$_SESSION['translator']->get_language()?></dc:language>
    
    <?foreach ($TEMPLATE_OUT['chat_channels'] as $_channel){?>
      <foaf:ChatChannel rdf:about="<?=$TEMPLATE_OUT['chat_link']?>">
       <foaf:name><?=$_channel?></foaf:name>
       <dc:description><?=$TEMPLATE_OUT[$_channel.'channel_message']?></dc:description>
        <foaf:chatEventList>
          <rdf:Seq>
            <?foreach ($TEMPLATE_OUT[$_channel.'all_lines_said'] as $_line){?>
              <rdf:li>
               <foaf:chatEvent rdf:ID="<?=next($TEMPLATE_OUT[$_channel.'all_lines_time1'])?>">
                <dc:date><?=next($TEMPLATE_OUT[$_channel.'all_lines_time2'])?></dc:date>
                <dc:description><?=$_line?></dc:description>
                <dc:creator><wn:Person foaf:nick="<?=next($TEMPLATE_OUT[$_channel.'all_lines_sender'])?>"/></dc:creator>
               </foaf:chatEvent>
              </rdf:li>
            <?}?>
          </rdf:Seq>
        </foaf:chatEventList>

        <foaf:Group>
         <foaf:member>
          <?foreach ($TEMPLATE_OUT[$_channel.'channel_chatters'] as $_chatters){?>
            <foaf:Person>
              <foaf:holdsAccount>
                <foaf:OnlineAccount>
                  <rdf:type rdf:resource="http://xmlns.com/foaf/0.1/OnlineChatAccount"/>
                  <foaf:accountServiceHomepage rdf:resource="<?=$TEMPLATE_OUT['chat_link']?>"/>
                  <foaf:accountName><?=$_chatters['NICK']?></foaf:accountName>
                </foaf:OnlineAccount>
              </foaf:holdsAccount>
            </foaf:Person>
          <?}?>
         </foaf:member>
        </foaf:Group>
      </foaf:ChatChannel>
    <?}?>
  </foaf:Agent>
</rdf:RDF>